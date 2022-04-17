from bs4 import BeautifulSoup
from random import randint
from time import sleep
import requests
import csv

header = ['Name', 'Rarity', 'Price']

html_text = requests.get('https://shop.tcgplayer.com/price-guide/pokemon/swsh07-evolving-skies').text
soup = BeautifulSoup(html_text, 'lxml')
select = soup.find_all('select', class_='priceGuideDropDown')
options = select[1].find_all('option')
for option in options:
    url = 'https://shop.tcgplayer.com/price-guide/pokemon/' + option['value']
    print(url)
    page = requests.get(url).text
    soop = BeautifulSoup(page, 'lxml')
    cards = soop.find_all('tr', class_='even') + soop.find_all('tr', class_='odd')

    with open('cards.csv', 'a') as f:
        writer = csv.writer(f)
        writer.writerow(header)

        for card in cards:
            name = card.find('div', class_='productDetail').text.replace('\n', '')
            price = card.find('td', class_='marketPrice').find('div', class_='cellWrapper').text\
                .replace(' ', '').replace('\n', '')
            rarity = card.find('td', class_='rarity').find('div', class_='cellWrapper').text\
                .replace('  ', '').replace('\n', '')
            data = [name, rarity, price]
            writer.writerow(data)
    # sleep(randint(2, 6))
