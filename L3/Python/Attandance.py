import re
import requests
from urllib.parse import quote_plus

URL = "https://scce.ac.in/parentm/"

USER_AGENT = (
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
    "AppleWebKit/537.36 (KHTML, like Gecko) "
    "Chrome/139.0.0.0 Safari/537.36"
)


def get_attendance(hall_ticket_number):
    try:
        # Session automatically maintains cookies
        session = requests.Session()

        session.headers.update({
            "User-Agent": USER_AGENT
        })

        # Open portal first
        session.get(
            URL,
            headers={
                "Accept": "text/html"
            },
            timeout=15
        )

        # Submit Hall Ticket Number
        form_data = {
            "HallticketNo": hall_ticket_number,
            "submit": "Login"
        }

        response = session.post(
            URL,
            data=form_data,
            headers={
                "User-Agent": USER_AGENT,
                "Referer": URL,
                "Origin": "https://scce.ac.in",
                "Content-Type": "application/x-www-form-urlencoded",
                "Accept": "text/html"
            },
            timeout=15
        )

        # The server may return HTTP 500 but still contain
        # the actual attendance page.
        html = response.text

        # Convert HTML to readable text
        text = re.sub(
            r"(?is)<script.*?</script>",
            " ",
            html
        )

        text = re.sub(
            r"(?is)<style.*?</style>",
            " ",
            text
        )

        text = re.sub(
            r"(?i)<br\s*/?>",
            "\n",
            text
        )

        text = re.sub(
            r"(?i)</tr>",
            "\n",
            text
        )

        text = re.sub(
            r"(?i)</td>",
            " ",
            text
        )

        text = re.sub(
            r"<[^>]+>",
            " ",
            text
        )

        text = text.replace("&nbsp;", " ")

        text = re.sub(
            r"\s+",
            " ",
            text
        ).strip()

        # Find:
        # Total 123 456 86%
        total_pattern = re.compile(
            r"(?i)Total\s+\d+\s+\d+\s+"
            r"(\d+(?:\.\d+)?)\s*%"
        )

        total_match = total_pattern.search(text)

        if total_match:
            return f"Attendance: {total_match.group(1)}%"

        # Backup: find attendance near "Total"
        backup_pattern = re.compile(
            r"(?i)Total.*?"
            r"(\d+(?:\.\d+)?)\s*%"
        )

        backup_match = backup_pattern.search(text)

        if backup_match:
            return f"Attendance: {backup_match.group(1)}%"

        return "Attendance not found."

    except requests.RequestException as e:
        return f"Error: {e}"

    except Exception as e:
        return f"Error: {e}"


def main():
    hall_ticket_number = input(
        "Enter the Hall Ticket Number: "
    ).strip()

    if not hall_ticket_number:
        print("Hall Ticket Number cannot be empty.")
        return

    print("\nChecking attendance...")

    result = get_attendance(hall_ticket_number)

    print(f"\n{result}")


if __name__ == "__main__":
    main()