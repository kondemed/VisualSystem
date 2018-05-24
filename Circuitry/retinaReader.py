
import serial
from Tkinter import *
import time

# GLOBAL VARS
master = Tk()
top = Toplevel()

w = Canvas(master, width=600, height=400)
w.pack()
w2 = Canvas(top, width=600, height=400)
w2.pack()

arr = [None] * 40
arr2 = [None] * 40
ganglia = [None] * 13
rods = [None] * 29

# CENTER_WEIGHT = 8
# SURROUND_WEIGHT = 1 

shades = ['#101010', '#303030', '#505050', '#696969', '#888888', '#A8A8A8', '#BEBEBE', '#D3D3D3', '#E8E8E8', '#FFFFFF']
shades2 = ['#000000', '#101010', '#202020', '#303030', '#404040', '#505050', '#606060', '#696969', '#787878', '#888888', '#989898', '#A8A8A8', '#B0B0B0', '#BEBEBE', '#C8C8C8', '#D3D3D3', '#DCDCDC', '#E8E8E8', '#F5F5F5', '#FFFFFF']

serial_port = '/dev/tty.usbmodem1421';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)


for row in range(5):
	for col in range(7):
		# stagger even/odd rows
		if row%2 == 0:
			offset = 35
		else:
			offset = 0

		# top & bottom rows
		if row==0 or row==4:
			if col != 0 and col!= 6:
				arr[row+col*5] = w.create_rectangle(col*70+5+offset, row*70+5, col*70+70+offset, row*70+70, fill="green")

		# intermediate rows
		elif row==1 or row==3:
			if col!= 0:
				arr[row+col*5] = w.create_rectangle(col*70+5+offset, row*70+5, col*70+70+offset, row*70+70, fill="green")
				if col != 1 and col != 6:
					arr2[row+col*5] = w2.create_rectangle(col*70+5+offset, row*70+5, col*70+70+offset, row*70+70, fill="blue") 

		# middle row
		else:
			arr[row+col*5] = w.create_rectangle(col*70+5+offset, row*70+5, col*70+70+offset, row*70+70, fill="green")
			if col != 0 and col != 6:
				arr2[row+col*5] = w2.create_rectangle(col*70+5+offset, row*70+5, col*70+70+offset, row*70+70, fill="blue") 

w.update()
w2.update()

print "ARRAY! " 
while None in arr:
	arr.remove(None)
arr = sorted(arr)
print arr
print "\n\n\n"

print "ARRAY 2! " 
while None in arr2:
	arr2.remove(None)
arr2 = sorted(arr2)
print arr2
print "\n\n\n"


ser = serial.Serial(serial_port, baud_rate)

while True:
    incoming = ser.readline().split(",");
    incoming[-1] = -1
    rodsOrGanglia = 0

    for i in range(len(incoming)):

    	if incoming[i] == "*":
    		# print 'HALLELUJAH'
    		rodsOrGanglia = 1
    		continue
    	else: 
    		try:
		    	if rodsOrGanglia == 0:
		    		rods[i] = int(incoming[i])
		    		val = rods[i]
			    	shade_idx = val/100
			    	w.itemconfig(arr[i], fill=shades[shade_idx])
		    	else:
		    		new_idx = i-(len(rods)+1)
		    		ganglia[new_idx] = int(incoming[i])
		    		val = ganglia[new_idx]
		    		shade_idx = val/5 + 15
		    		w2.itemconfig(arr2[new_idx], fill=shades2[shade_idx])
	    	except:
		    	print 'nope: {0}'.format(incoming[i])
		    	pass

	print "RODS: {0}".format(rods)
	print "GANGLIA: {0}".format(ganglia)


    	# try:
	    # 	rods[i] = int(''.join(c for c in rods[i] if c.isdigit()).replace('\'', ''))
	    # 	val = rods[i]
	    # 	print val
	    # 	shade_idx = val/100
	    # 	w.itemconfig(arr[i], fill=shades[shade_idx])
	    # 	print "rods! {0}".format(rods)

    	# except:
    	# 	pass

	# if len(rods) >= 28:
	#     # calculate ganglionic firing rates from receptive fields
	# 	for i in range(len(ganglia)): 
	# 		# print i
	# 		# print rods

	# 		if i<4: # row 2
	# 			ganglia[i] = -1
	# 			# ganglia[i] = (CENTER_WEIGHT * rods[i+6]) - SURROUND_WEIGHT * (rods[i] + rods[i+1] + rods[i+5] + rods[i+7] + rods[i+12] + rods[i+13])
	# 		elif (i<9): # row 3
	# 			ganglia[i] = (CENTER_WEIGHT * rods[i+8]) - SURROUND_WEIGHT * (rods[i+1] + rods[i+2] + rods[i+7] + rods[i+9] + rods[i+14] + rods[i+15])
	# 		elif (i<14): #row 4
	# 			ganglia[i]  = (CENTER_WEIGHT * rods[i+10]) - SURROUND_WEIGHT * (rods[i+3] + rods[i+4] + rods[i+9] + rods[i+11] + rods[i+15] + rods[i+16])

	# 		# print ganglia[i]
	# 		# w2.itemconfig(arr2[i], fill=ganglia[i]/100)

    w.update()
    w2.update()



