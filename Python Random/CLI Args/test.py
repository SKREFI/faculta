import argparse
parser = argparse.ArgumentParser()

parser.add_argument("action", help="Choose the way you display the information.",
                    type=str, choices=["display", "csvfil"])
parser.add_argument(
    "-n", "--number", help="How manny objects to extract from database.", type=int,
    required=True)
parser.add_argument(
    "-f", "--file", help="Destination file if case of csv export.", type=str)
parser.add_argument("-s", "--start_date",
                    help="Filrer by start date.", type=str)
parser.add_argument("-e", "--end_date", help="Filter by end date.", type=str)
parser.add_argument("-filt", "--filter",
                    help="Filter by custom condition.", type=str)
a = parser.parse_args()
print(a)
print(a.action, a.number, a.file, a.start_date, a.end_date)
