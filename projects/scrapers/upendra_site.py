# -*- coding: utf-8 -*-
import scrapy


class FirstscraperSpider(scrapy.Spider):
    name = 'upendra_scraper'
    # allowed_domains = ['enter_url_here']
    start_urls = [
        'https://scrapeit.home.blog']

    def parse(self, response):
        self.log(f'Got response from {response.url}')

        l = response.css('.post')
        for i in l:
            item = {
                'title': i.css('.entry-header > .entry-title > a::text').get(),
                'text': i.css('.entry-content > p::text').get(),
                'author': i.css('.entry-footer > .byline > .author > a::text').get(),
                'date': i.css('.entry-footer > .posted-on > a > .entry-date::text').get(),
                'category': i.css('.entry-footer > .cat-links > a::text').getall(),
                'tags': i.css('.entry-footer > .tags-links > a::text').getall()
            }
            yield item

        next_url = response.css('.nav-next-text').get()
        if next_url:
            next_url = response.urljoin(next_url)
            yield scrapy.Request(url=next_url, callback=self.parse)
