#!/usr/bin/env python3

import re
import copy
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# import user defined libraries
from players import *
from matches import *
from tournament import *
from display import *


PG_initial = []    
Players_Total = 0  
PayOff = []        
RPM = 0            
T_MAX = 0          
PR = 0             
M = 0              
Players = {"CH" : 0, "CO" : 1, "R" : 2, "CC" : 3, 
"CK" : 4, "GR" : 5, "ST" : 6, "DE" : 7}
Players_index = {0 : "CH", 1 : "CO", 2 : "R", 3 : 
"CC", 4 : "CK", 5 : "GR", 6 : "ST", 7 : "DE"}


input_file = open("input.txt", "r")
Population = [2,3,4,5,6,7,8,9]
Pay_offs = [13,14,15,16]

line_counter = 0

for a_line in input_file:
    line_counter+=1
    
    if line_counter in Population:
        PG_initial.append(int((re.search(':(.*):', a_line)).group(1)))
        continue
    
    if (line_counter in Pay_offs):
        PayOff.append(int((re.search(':(.*):', a_line)).group(1))) 
        continue
    
    if (line_counter == 21):
        RPM = int((re.search(':(.*):', a_line)).group(1))
        continue
        
    if (line_counter == 24):
        T_MAX = int((re.search(':(.*):', a_line)).group(1))
        continue
        
    if (line_counter == 27):
        PR = int((re.search(':(.*):', a_line)).group(1))
        continue
    
    if (line_counter == 30):
        M = float((re.search(':(.*):', a_line)).group(1))
        continue

input_file.close()

Players_Total = sum(PG_initial)
PG = np.array([PG_initial])

run_simulation = True
sim_counter = 0

while(run_simulation == True):
    PG_current = PG[-1]
    max_players = max(PG_current)

    if ((max_players == Players_Total) or (sim_counter>=T_MAX)):
        run_simulation = False 

        if (sim_counter==T_MAX):
            print("Maximum Tournament Limit Reached")
        
        dataframe = pd.DataFrame({
            'CH':PG[:,0],'CO':PG[:,1],'R':PG[:,2],'CC':PG[:,3],
            'CK':PG[:,4],'GR':PG[:,5],'ST':PG[:,6],'DE':PG[:,7]
        })

        display_result(dataframe)

        np.savetxt('PG_distribution.csv',PG,delimiter=',')
        np.savetxt('PG_distribution.txt',PG,delimiter=',')
        
    else :
        new_PG_dist = play_a_tournament(PG_current,M,PR,RPM,PayOff)
        PG = np.vstack([PG,new_PG_dist])
        sim_counter+=1
        