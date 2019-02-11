#!/usr/bin/env python3.6

# FILE: EightBall.py
# AUTHOR: Max Cooper
# PURPOSE: Graphical display of an eight ball that tells your fortune.


## IMPORTS ##
import tkinter as tk
import random as rand

## VARIABLES ##
responses = ["No sir", "Absolutely", "It's hard to say", "You will likely be disappointed",
"I wouldn't count on it", "Chances seem good", "Things look good", "What fun would telling you be?"]

## CLASSES ##

class Application(tk.Frame):
	def __init__(self, master=None):
		super().__init__(master)
		self.master = master
		self.pack()
		self.master.minsize(500, 500)
		self.create_widgets()

	def create_widgets(self):
		self.hi_there = tk.Button(self)
		self.hi_there["text"] = "Hello World\n(click me)"
		self.hi_there["command"] = self.say_hi
		self.hi_there.pack(side="top")

		self.quit = tk.Button(self, text="QUIT", fg="red", command=self.master.destroy)
		self.quit.pack(side="bottom")

	def say_hi(self):
		print("Hi there, everyone!")

## FUNCTIONS ##
def randomAnswer():
	"""
	randomAnswer - Selects one of the random eight ball answers defined in responses.

	- Params
	  - None
	- Returns: String containing the eight ball's answer.
	"""
	ansIndex = rand.randint(0, len(responses)-1)
	return responses[ansIndex]

## MAIN ##
root = tk.Tk()
app = Application(master=root)
app.mainloop()
