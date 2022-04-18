from bs4 import BeautifulSoup
from random import randint
from time import sleep
import requests
import csv

header = ['Name', 'Rarity', 'Price', 'Set']

html_text = requests.get('https://shop.tcgplayer.com/price-guide/pokemon/swsh07-evolving-skies').text
soup = BeautifulSoup(html_text, 'lxml')
select = soup.find_all('select', class_='priceGuideDropDown')
options = select[1].find_all('option')
for option in options:
    card_set = option.text.strip()
    url = 'https://shop.tcgplayer.com/price-guide/pokemon/' + option['value']
    print(url)
    print(card_set)
    page = requests.get(url).text
    soop = BeautifulSoup(page, 'lxml')
    cards = soop.find_all('tr', class_='even') + soop.find_all('tr', class_='odd')

    with open('cards.csv', 'a') as f:
        writer = csv.writer(f, delimiter=',')
        writer.writerow(header)

        for card in cards:
            name = card.find('div', class_='productDetail').text.strip("\n").strip()
            price = card.find('td', class_='marketPrice').find('div', class_='cellWrapper').text.strip("\n").strip()
            rarity = card.find('td', class_='rarity').find('div', class_='cellWrapper').text.strip("\n").strip()
            data = [name, rarity, price, card_set]
            writer.writerow(data)

        sleep(randint(0, 2))
