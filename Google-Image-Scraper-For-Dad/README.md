# Google Image Scraper for Dad

### Requirements and `pip` Installations
  #### 1) selenium 
     pip install selenium 
  #### 2) chromedriver_autoinstaller 
     pip install chromedriver-autoinstaller 
  #### 3) tkinter 
     pip install tk 

### Basic Usage
This program first has you choose the desired location and name of the created folder which will house the downloaded 
images (via the same). 

It then takes as input a search query and a number of images you would like to download. It then opens up an instance 
of Google Chrome through the Chrome Driver. The program iterates through each of the images, opening the full image 
(as opposed to just downloading the thumbnail) and downloading the full image to the newly created folder in the 
format: "query (X).jpg" 
<br/><br/>
### OS Notes
Please note that as of October 2022, this program has only been tested on Linux (Ubuntu 22.04 LTS). 
<br/><br/>
### A Note on Image #25n
In Google Images, every 25th element is not an image, but instead a small box of possible search options. This downloader 
will thus skip those XPaths and spit out a note informing the user of such. 
