package Daywise.L3;

import java.net.CookieManager;
import java.net.CookiePolicy;
import java.net.URI;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Attendance {

    private static final String URL =
            "https://scce.ac.in/parentm/";

    private static final String USER_AGENT =
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                    + "AppleWebKit/537.36 (KHTML, like Gecko) "
                    + "Chrome/139.0.0.0 Safari/537.36";

    public static String getAttendance(String hallTicketNumber) {

        try {

            CookieManager cookieManager =
                    new CookieManager(
                            null,
                            CookiePolicy.ACCEPT_ALL
                    );

            HttpClient client = HttpClient.newBuilder()
                    .cookieHandler(cookieManager)
                    .followRedirects(HttpClient.Redirect.NORMAL)
                    .build();

            // Open portal first
            HttpRequest getRequest =
                    HttpRequest.newBuilder()
                            .uri(URI.create(URL))
                            .header("User-Agent", USER_AGENT)
                            .header("Accept", "text/html")
                            .GET()
                            .build();

            client.send(
                    getRequest,
                    HttpResponse.BodyHandlers.ofString()
            );

            // Submit Hall Ticket Number
            String formData =
                    "HallticketNo="
                            + URLEncoder.encode(
                            hallTicketNumber,
                            StandardCharsets.UTF_8
                    )
                            + "&submit=Login";

            HttpRequest postRequest =
                    HttpRequest.newBuilder()
                            .uri(URI.create(URL))
                            .header("User-Agent", USER_AGENT)
                            .header("Referer", URL)
                            .header("Origin", "https://scce.ac.in")
                            .header(
                                    "Content-Type",
                                    "application/x-www-form-urlencoded"
                            )
                            .header("Accept", "text/html")
                            .POST(
                                    HttpRequest.BodyPublishers
                                            .ofString(formData)
                            )
                            .build();

            HttpResponse<String> response =
                    client.send(
                            postRequest,
                            HttpResponse.BodyHandlers.ofString()
                    );

            // IMPORTANT:
            // The server returns HTTP 500 but still sends
            // the actual attendance page.
            String html = response.body();

            // Convert HTML to readable text
            String text = html
                    .replaceAll(
                            "(?is)<script.*?</script>",
                            " "
                    )
                    .replaceAll(
                            "(?is)<style.*?</style>",
                            " "
                    )
                    .replaceAll(
                            "(?i)<br\\s*/?>",
                            "\n"
                    )
                    .replaceAll(
                            "(?i)</tr>",
                            "\n"
                    )
                    .replaceAll(
                            "(?i)</td>",
                            " "
                    )
                    .replaceAll(
                            "<[^>]+>",
                            " "
                    )
                    .replaceAll(
                            "&nbsp;",
                            " "
                    )
                    .replaceAll(
                            "\\s+",
                            " "
                    )
                    .trim();

            // Find "Total ... 86%"
            Pattern totalPattern =
                    Pattern.compile(
                            "(?i)Total\\s+\\d+\\s+\\d+\\s+"
                                    + "(\\d+(?:\\.\\d+)?)\\s*%"
                    );

            Matcher totalMatcher =
                    totalPattern.matcher(text);

            if (totalMatcher.find()) {

                return "Attendance: "
                        + totalMatcher.group(1)
                        + "%";
            }

            // Backup: find attendance near "Total"
            Pattern backupPattern =
                    Pattern.compile(
                            "(?i)Total.*?"
                                    + "(\\d+(?:\\.\\d+)?)\\s*%"
                    );

            Matcher backupMatcher =
                    backupPattern.matcher(text);

            if (backupMatcher.find()) {

                return "Attendance: "
                        + backupMatcher.group(1)
                        + "%";
            }

            return "Attendance not found.";

        } catch (Exception e) {

            return "Error: " + e.getMessage();
        }
    }

    public static void main(String[] args) {

        Scanner scanner =
                new Scanner(System.in);

        System.out.print(
                "Enter the Hall Ticket Number: "
        );

        String hallTicketNumber =
                scanner.nextLine().trim();

        if (hallTicketNumber.isEmpty()) {

            System.out.println(
                    "Hall Ticket Number cannot be empty."
            );

            scanner.close();
            return;
        }

        System.out.println(
                "\nChecking attendance..."
        );

        String result =
                getAttendance(hallTicketNumber);

        System.out.println("\n" + result);

        scanner.close();
    }
}