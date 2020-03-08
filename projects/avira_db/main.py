from os import getcwd as wd

from db.Database import ProductDatabase


if __name__ == '__main__':
    path = wd() + '/db/Products.csv'

    # IDs: prime, pro, vpn, pass, opt, speed
    products = ProductDatabase(path).products

    for key in products:
        print(products[key])
