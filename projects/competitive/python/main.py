class Revolut():
    def __init__(self, balanta, price=0):
        self.price = price
        self.bal = balanta
        self.btc = 0

    def __repr__(self):
        return 'Bal: {:.2f} | Btc: {:.2f}'.format(self.bal, self.btc)

    def leuToBtc(self, leu):
        return 1 / (self.price / leu)

    def btcToLeu(self, btc):
        return btc * self.price

    def buyBtc(self, leu):
        if self.bal < leu:
            print('Balance not enough to buy BTC')
            return
        self.btc += self.leuToBtc(leu)
        self.bal -= leu

    def sellBtc(self, btc):
        if btc < self.btc:
            print('Not enough btc to sell')
        self.btc -= btc
        self.bal += self.btcToLeu(btc)


if __name__ == "__main__":
    r = Revolut(100, 39000)
    for _ in range(100):
        r.buyBtc(r.bal)
        r.price += 1000
        r.sellBtc(r.btc)
        print(r)
