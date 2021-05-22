import requests, json
url = "https://api.dictionaryapi.dev/api/v2/entries/en_US/"
word = input("Enter word : ")
complete_url = url + word
response = requests.get(complete_url)
x = response.json()
for definitions in x:
    print("defination:{}".format(definitions['meanings'][0]['definitions'][0]['definition']))