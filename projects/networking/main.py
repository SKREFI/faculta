import requests
import json

from models import Articles, Source, Response

# base_url = 'http://newsapi.org/v2/everything'

# args = {
#     'q': 'bitcoin',
#     'from': '2020-02-29',
#     'sortBy': 'publishedAt',
#     'apiKey': 'c45df283c7fd4b078d32086c854fc58d'
# }

# r = requests.get(base_url, params=args)

# print((r.encoding))

# j = json.loads(r.text)

with open('data.json', 'rb') as f:
    j = json.load(f)

r = Response(**j)

# for a in (r.articles):
# print((a))

print(r.articles[0].title)
