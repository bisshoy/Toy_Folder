# Hi Dad!

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By 

from tkinter import Tk
from tkinter.filedialog import askdirectory
from tkinter.filedialog import askopenfilename 

import chromedriver_autoinstaller
import time 
import os

# SELECT CHROME DRIVER FILE 
Tk().withdraw() 
chromedriver_autoinstaller.install()


# CREATE NEW FOLDER IN WHICH TO STORE IMAGES  
print("Please select desired location of created folder")
FOLDER_LOCATION = askdirectory(title="Select location of created folder") + "/"

TARGET_FOLDER = input("Name of created folder: ")
newfolder = FOLDER_LOCATION + TARGET_FOLDER  
if not os.path.exists(newfolder): 
    os.makedirs(newfolder)

FINAL_FOLDER = newfolder + "/"
print("Your selected location is: " + FINAL_FOLDER + "\n")


# USER INPUT QUERY AND NUMBER OF IMAGES 
query = input("What is your search query?: ")
num = int(input("How many images?: "))
NUMBER_OF_IMAGES = num + 1
print("") 


# OPEN GOOGLE IMAGES THROUGH DRIVER 
driver = webdriver.Chrome() 
driver.maximize_window()
driver.get("https://www.google.com/imghp?hl=en&ogbl=")


# HAVE COMPUTER ENTER SEARCH QUERY VIA SELENIUM 
box = driver.find_element(By.XPATH, '/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input') #XPath of Search Bar 
box.send_keys(query)
box.send_keys(Keys.ENTER)


# FUNCTION TO SCROLL TO BOTTOM OF IMAGE RESULTS 
def scroll_to_bottom():

    last_height = driver.execute_script("\
    return document.body.scrollHeight")

    while True:
        driver.execute_script("\
        window.scrollTo(0,document.body.scrollHeight)")
 
        # waiting for the results to load
        time.sleep(3)
 
        new_height = driver.execute_script("\
        return document.body.scrollHeight")
 
        # click on "Show more results" (if exists)
        try:
            driver.find_element(By.CSS_SELECTOR, ".YstHxe input").click() 
            time.sleep(3)
        except:
            pass
 
        # Checking if we have reached the bottom of the page
        if new_height == last_height:
            break
 
        last_height = new_height


# CALL FUNCTION TO SCROLL TO BOTTOM OF IMAGES PAGE
# FUNCTION ONLY CALLS IF LARGER NUMBER OF IMAGES REQUIRED 
if NUMBER_OF_IMAGES >= 21:
    scroll_to_bottom() 


# LOOP TO SAVE DESIRED NUMBER OF IMAGES 
for i in range(1, NUMBER_OF_IMAGES):
    try:
        # Clicks on each thumbnail so that you ca access the full image 
        element = driver.find_element(By.XPATH, '//*[@id="islrg"]/div[1]/div[' + str(i) + ']/a[1]/div[1]/img') 
        element.click() 

        # Time delay to allow image to load fully 
        # Increase delay if on slower internet  
        time.sleep(3)

        # Finds XPath of every full image 
        img = driver.find_element(By.XPATH, '//*[@id="Sva75c"]/div/div/div/div[3]/div[2]/c-wiz/div[2]/div[1]/div[1]/div[2]/div/a/img')

        # Saves it as a JPEG
        img.screenshot(FINAL_FOLDER + query + " (" + str(i) + ").jpg")

        # Just to avoid unwanted errors 
        # Mainly here for my paranoia's sake, in case download time 
        # goes too long 
        # Feel free to remove if you don't like it, though decreasing the 
        # length of the delay might be safer 
        time.sleep(1)

    except:
        # The element every 25 XPaths is a small box of supplementary search options, not  
        # an image; thus it will be skipped. The if-statement below will spit out an error 
        # message every 25 images to notify the user 
        if int(i) % 25 == 0:
            print("\nNOTE: The element of XPath" + '//*[@id="islrg"]/div[1]/div[' + str(i) + ']/a[1]' + "is not an image. Thus, it was not downloaded.\n")
        
        # In case of other error attempting to download image 
        # Anecdotally, this only happens when the pre-download delay is set too low 
        else:
            print("ERROR: Could not download Image #" + str(i))
        
        continue


# NOTIFY USER OF PROCESS COMPLETION  
print("\nProcess completed!")


# CLOSE DRIVER 
driver.close() 
