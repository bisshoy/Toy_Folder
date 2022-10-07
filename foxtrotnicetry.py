import random 
import webbrowser

year = str(random.randint(1988, 2020))
month = str(random.randint(1, 12)) 
day = str(random.randint(1, 31))

date = "https://www.gocomics.com/foxtrot/" + year + "/" + month + "/" + day

print(date)
webbrowser.open(date) 