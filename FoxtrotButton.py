from tkinter import *
import webbrowser

def open_page():
    webbrowser.get('firefox').open('https://www.gocomics.com/random/foxtrot')

print("Thank you for using the Foxtrot button! I love you!")

#Creates Tk window
master = Tk()
master.geometry("500x250+700+300")
master.title("Foxtrot Button!")

#Creates a Frame which can expand according to the size of the window
pane = Frame(master)
pane.pack(fill = BOTH, expand = True)

#Button 1
b1 = Button(pane, text = "Click me for Foxtrot!", background = "#33D5FF", activebackground = "#F6E277", fg = "black", font = ("Arial", 35), command = open_page)
b1.pack(side = TOP, expand = True, fill = BOTH)

#Button 2
b2 = Button(pane, text = "QUIT", background = "#EE5D5D", activebackground = "#F6E277", fg = "white", command = quit)
b2.pack(side = TOP, expand = False, fill = BOTH) #TURN EXPAND TO TRUE TO EVEN OUT BUTTONS 

#Execute Tkinter
master.mainloop() 
