import urllib2  # works fine with Python 2.7.9 (not 3.4.+)
import json
import time
import sys

def fetchPreMarket(symbol, exchange):
    link = "http://finance.google.com/finance/info?client=ig&q="
    url = link+"%s:%s" % (exchange, symbol)
    try:
        u = urllib2.urlopen(url)
    except:
       print ("Could not find stock "+str(symbol)+" on exchange "+str(exchange))
       sys.exit()

    content = u.read()
    data = json.loads(content[3:])

    info = data[0]

    t = str(info["lt"])    # time stamp (elt for after hours and pre market)
    l = float(info['l'])    # market price

    return (t,l)

p0 = 0
time.sleep(0.6)

symbol = raw_input('Enter the ticker symbol: ')
exchange = raw_input('Enter the exchange: ')
    #  symbol = "rbs"
    #  exchange = "lon" 
while True:
    t, l = fetchPreMarket(symbol,exchange)
    if(l!=p0):
        p0 = l
        print("%s\t%.2f" % (t, l))
