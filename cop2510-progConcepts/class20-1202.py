# Intro to tkinter
import tkinter

class TestAvg:
    def __init__(self):
        self.mainwindow = tkinter.Tk() # creates the window

        self.test1frame = tkinter.Frame(self.mainwindow) # creates a frame/segment in that window
        self.test2frame = tkinter.Frame(self.mainwindow)
        self.test3frame = tkinter.Frame(self.mainwindow)
        self.avgframe = tkinter.Frame(self.mainwindow)
        self.buttonframe = tkinter.Frame(self.mainwindow)

        self.test1label = tkinter.Label(self.test1frame, text='Enter the score for test 1: ')
        self.test1entry = tkinter.Entry(self.test1frame, width=10)
        self.test2label = tkinter.Label(self.test2frame, text='Enter the score for test 2: ')
        self.test2entry = tkinter.Entry(self.test2frame, width=10)
        self.test3label = tkinter.Label(self.test3frame, text='Enter the score for test 3: ')
        self.test3entry = tkinter.Entry(self.test3frame, width=10)

        #----- packing the widgets -----
        self.test1label.pack(side='left')
        self.test1entry.pack(side='left')
        self.test2label.pack(side='left')
        self.test2entry.pack(side='left')
        self.test3label.pack(side='left')
        self.test3entry.pack(side='left')

        self.resultlabel = tkinter.Label(self.avgframe, text='Average: ')
        self.avg = tkinter.StringVar()
        self.avglabel = tkinter.Label(self.avgframe, textvariable=self.avg)
        self.resultlabel.pack(side='left')
        self.avglabel.pack(side='left')

        self.calc = tkinter.Button(self.buttonframe, text='Calculate', command=self.calcavg)
        self.calc.pack(side='left')

        # not using parenthesis in calcavg() and destroy() function, because we want it to run only when the button is pressed
        self.quit = tkinter.Button(self.buttonframe, text='Quit', command=self.mainwindow.destroy)
        self.quit.pack(side='left')

        #----- packing the frames -----
        self.test1frame.pack()
        self.test2frame.pack()
        self.test3frame.pack()
        self.avgframe.pack()
        self.buttonframe.pack()

        tkinter.mainloop() # keeps the window running

    def calcavg(self):
        self.test1 = float(self.test1entry.get())
        self.test2 = float(self.test2entry.get())
        self.test3 = float(self.test3entry.get())

        self.average = (self.test1 + self.test2 + self.test3) / 3.0
        self.avg.set(self.average)


#----- end class -----
#----- start program -----
testavg = TestAvg()
