# -*- coding: utf-8 -*-
import scrapy


class FirstscraperSpider(scrapy.Spider):
    name = 'upendra_scraper'
    # allowed_domains = ['enter_url_here']
    start_urls = [
        '._2nlv']

    # parse states
    def parse(self, response):
        self.log(f'Got all states from {response.url}')
        
        yield response.css('._2nlv::text').get()
        
