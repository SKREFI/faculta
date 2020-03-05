# -*- coding: utf-8 -*-
import scrapy


class FirstscraperSpider(scrapy.Spider):
    name = 'firstScraper'
    # allowed_domains = ['enter_url_here']
    start_urls = [
        'http://quotes.toscrape.com']

    def parse(self, response):
        self.log(f'Got response from {response.url}')
        quotes = response.css('.quote')
        for quote in quotes:
            yield {
                'author': quote.css('.author::text').get(),
                'quote': quote.css('.text::text').get(),
                'tags': quote.css('.tag::text').getall(),
            }

        next_url = response.css('li.next > a::attr(href)').get()
        if next_url:
            next_url = response.urljoin(next_url)
            yield scrapy.Request(url=next_url, callback=self.parse)
