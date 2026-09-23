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

public class CGPA {

    private static final String RESULTS_PAGE =
            "https://www.scce.ac.in/exam_result.php";

    private static final String USER_AGENT =
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                    + "AppleWebKit/537.36 (KHTML, like Gecko) "
                    + "Chrome/139.0.0.0 Safari/537.36";

    public static String getCGPA(String hallTicketNumber) {

        try {

            CookieManager cookieManager =
                    new CookieManager(
                            null,
                            CookiePolicy.ACCEPT_ALL
                    );

            HttpClient client =
                    HttpClient.newBuilder()
                            .cookieHandler(cookieManager)
                            .followRedirects(
                                    HttpClient.Redirect.NORMAL
                            )
                            .build();

            /*
             * =========================================================
             * STEP 1
             * Open SCCE Exam Results page
             * =========================================================
             */

            HttpRequest request =
                    HttpRequest.newBuilder()
                            .uri(
                                    URI.create(
                                            RESULTS_PAGE
                                    )
                            )
                            .header(
                                    "User-Agent",
                                    USER_AGENT
                            )
                            .header(
                                    "Accept",
                                    "text/html,application/xhtml+xml"
                            )
                            .GET()
                            .build();

            HttpResponse<String> response =
                    client.send(
                            request,
                            HttpResponse.BodyHandlers.ofString()
                    );

            String html =
                    response.body();

            /*
             * =========================================================
             * STEP 2
             * Find CGPA result URL
             * =========================================================
             */

            String cgpaUrl =
                    findCGPALink(html);

            if (cgpaUrl == null) {

                return "CGPA result link not found.";
            }

            cgpaUrl =
                    URI.create(
                                    RESULTS_PAGE
                            )
                            .resolve(
                                    cgpaUrl
                            )
                            .toString();

            /*
             * =========================================================
             * STEP 3
             * Open CGPA page
             * =========================================================
             */

            HttpRequest cgpaPageRequest =
                    HttpRequest.newBuilder()
                            .uri(
                                    URI.create(
                                            cgpaUrl
                                    )
                            )
                            .header(
                                    "User-Agent",
                                    USER_AGENT
                            )
                            .header(
                                    "Referer",
                                    RESULTS_PAGE
                            )
                            .header(
                                    "Accept",
                                    "text/html,application/xhtml+xml"
                            )
                            .GET()
                            .build();

            HttpResponse<String> cgpaPageResponse =
                    client.send(
                            cgpaPageRequest,
                            HttpResponse.BodyHandlers.ofString()
                    );

            String cgpaPage =
                    cgpaPageResponse.body();

            /*
             * =========================================================
             * STEP 4
             * Try to find CGPA directly
             * =========================================================
             */

            String cgpa =
                    extractCGPA(
                            cgpaPage
                    );

            if (cgpa != null) {

                return "CGPA: " + cgpa;
            }

            /*
             * =========================================================
             * STEP 5
             * Find input fields
             * =========================================================
             */

            String inputName =
                    findHallTicketInput(
                            cgpaPage
                    );

            /*
             * If there is no obvious Hall Ticket field,
             * find the first text input.
             */

            if (inputName == null) {

                inputName =
                        findFirstTextInput(
                                cgpaPage
                        );
            }

            if (inputName == null) {

                return "Hall Ticket input field not found.";
            }

            /*
             * =========================================================
             * STEP 6
             * Find form action
             * =========================================================
             */

            String action =
                    findFormAction(
                            cgpaPage
                    );

            if (action == null
                    || action.isBlank()) {

                action = cgpaUrl;
            }

            action =
                    URI.create(
                                    cgpaUrl
                            )
                            .resolve(
                                    action
                            )
                            .toString();

            /*
             * =========================================================
             * STEP 7
             * Find submit button
             * =========================================================
             */

            String submitName =
                    findSubmitName(
                            cgpaPage
                    );

            String submitValue =
                    findSubmitValue(
                            cgpaPage
                    );

            /*
             * =========================================================
             * STEP 8
             * Build POST data
             * =========================================================
             */

            StringBuilder data =
                    new StringBuilder();

            data.append(
                    URLEncoder.encode(
                            inputName,
                            StandardCharsets.UTF_8
                    )
            );

            data.append("=");

            data.append(
                    URLEncoder.encode(
                            hallTicketNumber,
                            StandardCharsets.UTF_8
                    )
            );

            /*
             * Include submit button if the form has one.
             */

            if (submitName != null) {

                data.append("&");

                data.append(
                        URLEncoder.encode(
                                submitName,
                                StandardCharsets.UTF_8
                        )
                );

                data.append("=");

                data.append(
                        URLEncoder.encode(
                                submitValue == null
                                        ? ""
                                        : submitValue,
                                StandardCharsets.UTF_8
                        )
                );
            }

            /*
             * =========================================================
             * STEP 9
             * Submit Hall Ticket
             * =========================================================
             */

            HttpRequest postRequest =
                    HttpRequest.newBuilder()
                            .uri(
                                    URI.create(
                                            action
                                    )
                            )
                            .header(
                                    "User-Agent",
                                    USER_AGENT
                            )
                            .header(
                                    "Referer",
                                    cgpaUrl
                            )
                            .header(
                                    "Content-Type",
                                    "application/x-www-form-urlencoded"
                            )
                            .header(
                                    "Accept",
                                    "text/html,application/xhtml+xml"
                            )
                            .POST(
                                    HttpRequest.BodyPublishers
                                            .ofString(
                                                    data.toString()
                                            )
                            )
                            .build();

            HttpResponse<String> resultResponse =
                    client.send(
                            postRequest,
                            HttpResponse.BodyHandlers.ofString()
                    );

            String resultHtml =
                    resultResponse.body();

            /*
             * =========================================================
             * STEP 10
             * Extract CGPA
             * =========================================================
             */

            cgpa =
                    extractCGPA(
                            resultHtml
                    );

            if (cgpa != null) {

                return "CGPA: " + cgpa;
            }

            /*
             * Convert HTML to text and try again.
             */

            String text =
                    htmlToText(
                            resultHtml
                    );

            cgpa =
                    extractCGPA(
                            text
                    );

            if (cgpa != null) {

                return "CGPA: " + cgpa;
            }

            /*
             * Backup parser.
             */

            cgpa =
                    backupCGPA(
                            text
                    );

            if (cgpa != null) {

                return "CGPA: " + cgpa;
            }

            return "CGPA not found.";

        } catch (Exception e) {

            return "Error: " + e.getMessage();
        }
    }


    /*
     * ================================================================
     * FIND CGPA LINK
     * ================================================================
     */

    private static String findCGPALink(
            String html
    ) {

        /*
         * Look for the CGPA text first.
         */

        String upper =
                html.toUpperCase();

        int cgpaPosition =
                upper.indexOf(
                        "RESULTS OF SCCE CGPA"
                );

        if (cgpaPosition == -1) {

            /*
             * Try less exact variants.
             */

            cgpaPosition =
                    upper.indexOf(
                            "SCCE CGPA"
                    );
        }

        if (cgpaPosition == -1) {
            return null;
        }

        /*
         * Search the nearby HTML for an href.
         */

        int start =
                Math.max(
                        0,
                        cgpaPosition - 1000
                );

        int end =
                Math.min(
                        html.length(),
                        cgpaPosition + 2000
                );

        String area =
                html.substring(
                        start,
                        end
                );

        /*
         * Prefer hrefs that appear AFTER the CGPA text.
         */

        String after =
                html.substring(
                        cgpaPosition,
                        Math.min(
                                html.length(),
                                cgpaPosition + 2000
                        )
                );

        Pattern hrefPattern =
                Pattern.compile(
                        "(?is)href\\s*=\\s*"
                                + "(['\"])(.*?)\\1"
                );

        Matcher matcher =
                hrefPattern.matcher(
                        after
                );

        while (matcher.find()) {

            String href =
                    matcher.group(2);

            if (href == null
                    || href.isBlank()) {
                continue;
            }

            /*
             * Don't accidentally select SCGPA.
             */

            String hrefLower =
                    href.toLowerCase();

            if (!hrefLower.contains("scgpa")) {

                return href;
            }
        }

        /*
         * Final fallback: inspect the complete area.
         */

        matcher =
                hrefPattern.matcher(
                        area
                );

        while (matcher.find()) {

            String href =
                    matcher.group(2);

            if (href == null
                    || href.isBlank()) {
                continue;
            }

            if (!href
                    .toLowerCase()
                    .contains("scgpa")) {

                return href;
            }
        }

        return null;
    }


    /*
     * ================================================================
     * FIND HALL TICKET INPUT
     * ================================================================
     */

    private static String findHallTicketInput(
            String html
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?is)<input\\b([^>]*)>"
                );

        Matcher matcher =
                pattern.matcher(
                        html
                );

        while (matcher.find()) {

            String attributes =
                    matcher.group(1);

            String name =
                    getAttribute(
                            attributes,
                            "name"
                    );

            String id =
                    getAttribute(
                            attributes,
                            "id"
                    );

            String placeholder =
                    getAttribute(
                            attributes,
                            "placeholder"
                    );

            String combined =
                    (
                            (name == null ? "" : name)
                                    + " "
                                    + (id == null ? "" : id)
                                    + " "
                                    + (placeholder == null
                                    ? ""
                                    : placeholder)
                    )
                            .toLowerCase();

            if (combined.contains("hall")
                    || combined.contains("ticket")
                    || combined.contains("htno")
                    || combined.contains("hallticket")) {

                if (name != null
                        && !name.isBlank()) {

                    return name;
                }

                if (id != null
                        && !id.isBlank()) {

                    return id;
                }
            }
        }

        return null;
    }


    /*
     * ================================================================
     * FIND FIRST TEXT INPUT
     * ================================================================
     */

    private static String findFirstTextInput(
            String html
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?is)<input\\b([^>]*)>"
                );

        Matcher matcher =
                pattern.matcher(
                        html
                );

        while (matcher.find()) {

            String attributes =
                    matcher.group(1);

            String type =
                    getAttribute(
                            attributes,
                            "type"
                    );

            String name =
                    getAttribute(
                            attributes,
                            "name"
                    );

            if (name == null
                    || name.isBlank()) {
                continue;
            }

            if (type == null
                    || type.equalsIgnoreCase("text")
                    || type.equalsIgnoreCase("search")) {

                return name;
            }
        }

        return null;
    }


    /*
     * ================================================================
     * FIND FORM ACTION
     * ================================================================
     */

    private static String findFormAction(
            String html
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?is)<form\\b([^>]*)>"
                );

        Matcher matcher =
                pattern.matcher(
                        html
                );

        if (matcher.find()) {

            return getAttribute(
                    matcher.group(1),
                    "action"
            );
        }

        return null;
    }


    /*
     * ================================================================
     * FIND SUBMIT NAME
     * ================================================================
     */

    private static String findSubmitName(
            String html
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?is)<input\\b([^>]*)>"
                );

        Matcher matcher =
                pattern.matcher(
                        html
                );

        while (matcher.find()) {

            String attributes =
                    matcher.group(1);

            String type =
                    getAttribute(
                            attributes,
                            "type"
                    );

            if (type != null
                    && type.equalsIgnoreCase(
                    "submit"
            )) {

                return getAttribute(
                        attributes,
                        "name"
                );
            }
        }

        return null;
    }


    /*
     * ================================================================
     * FIND SUBMIT VALUE
     * ================================================================
     */

    private static String findSubmitValue(
            String html
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?is)<input\\b([^>]*)>"
                );

        Matcher matcher =
                pattern.matcher(
                        html
                );

        while (matcher.find()) {

            String attributes =
                    matcher.group(1);

            String type =
                    getAttribute(
                            attributes,
                            "type"
                    );

            if (type != null
                    && type.equalsIgnoreCase(
                    "submit"
            )) {

                String value =
                        getAttribute(
                                attributes,
                                "value"
                        );

                return value == null
                        ? ""
                        : value;
            }
        }

        return "";
    }


    /*
     * ================================================================
     * GET ATTRIBUTE
     * ================================================================
     */

    private static String getAttribute(
            String attributes,
            String attribute
    ) {

        Pattern quoted =
                Pattern.compile(
                        "(?i)\\b"
                                + Pattern.quote(attribute)
                                + "\\s*=\\s*"
                                + "(['\"])(.*?)\\1"
                );

        Matcher matcher =
                quoted.matcher(
                        attributes
                );

        if (matcher.find()) {

            return matcher.group(2);
        }

        Pattern unquoted =
                Pattern.compile(
                        "(?i)\\b"
                                + Pattern.quote(attribute)
                                + "\\s*=\\s*"
                                + "([^\\s>]+)"
                );

        matcher =
                unquoted.matcher(
                        attributes
                );

        if (matcher.find()) {

            return matcher.group(1);
        }

        return null;
    }


    /*
     * ================================================================
     * EXTRACT CGPA
     * ================================================================
     */

    private static String extractCGPA(
            String content
    ) {

        String[] regexes = {

                "(?i)\\bCGPA\\b\\s*[:=\\-]\\s*"
                        + "(\\d+(?:\\.\\d+)?)",

                "(?i)\\bCGPA\\b\\s+"
                        + "(\\d+(?:\\.\\d+)?)",

                "(?i)C\\.?G\\.?P\\.?A\\.?"
                        + "\\s*[:=\\-]?\\s*"
                        + "(\\d+(?:\\.\\d+)?)",

                "(?i)Cumulative\\s+Grade\\s+Point"
                        + "\\s+Average\\s*"
                        + "[:=\\-]?\\s*"
                        + "(\\d+(?:\\.\\d+)?)"
        };

        for (String regex : regexes) {

            Pattern pattern =
                    Pattern.compile(
                            regex
                    );

            Matcher matcher =
                    pattern.matcher(
                            content
                    );

            while (matcher.find()) {

                String value =
                        matcher.group(1);

                try {

                    double number =
                            Double.parseDouble(
                                    value
                            );

                    if (number >= 0
                            && number <= 10) {

                        return value;
                    }

                } catch (NumberFormatException ignored) {
                }
            }
        }

        return null;
    }


    /*
     * ================================================================
     * BACKUP CGPA
     * ================================================================
     */

    private static String backupCGPA(
            String text
    ) {

        Pattern pattern =
                Pattern.compile(
                        "(?i)CGPA.{0,100}?"
                                + "(\\d+(?:\\.\\d+)?)"
                );

        Matcher matcher =
                pattern.matcher(
                        text
                );

        while (matcher.find()) {

            try {

                double value =
                        Double.parseDouble(
                                matcher.group(1)
                        );

                if (value >= 0
                        && value <= 10) {

                    return matcher.group(1);
                }

            } catch (NumberFormatException ignored) {
            }
        }

        return null;
    }


    /*
     * ================================================================
     * HTML TO TEXT
     * ================================================================
     */

    private static String htmlToText(
            String html
    ) {

        return html
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
                        "(?i)</th>",
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
                        "&amp;",
                        "&"
                )
                .replaceAll(
                        "&lt;",
                        "<"
                )
                .replaceAll(
                        "&gt;",
                        ">"
                )
                .replaceAll(
                        "\\s+",
                        " "
                )
                .trim();
    }


    /*
     * ================================================================
     * MAIN
     * ================================================================
     */

    public static void main(
            String[] args
    ) {

        Scanner scanner =
                new Scanner(
                        System.in
                );

        System.out.print(
                "Enter the Hall Ticket Number: "
        );

        String hallTicketNumber =
                scanner.nextLine()
                        .trim();

        if (hallTicketNumber.isEmpty()) {

            System.out.println(
                    "Hall Ticket Number cannot be empty."
            );

            scanner.close();

            return;
        }

        System.out.println(
                "\nChecking CGPA..."
        );

        String result =
                getCGPA(
                        hallTicketNumber
                );

        System.out.println(
                "\n" + result
        );

        scanner.close();
    }
}