
import math
import numpy as np

class Player():
    def __init__(self):
        self.score = 0
        self.history = []        

    def choice_after_mistake(self,initial_choice,M):
        p = np.random.uniform(0,1)
        #print(p)
        if p > M :
            mistake = False
        else :
            mistake = True

        if mistake == False:
            final_choice = initial_choice
        elif (mistake == True) and initial_choice=="0":
            final_choice = "1"
        elif (mistake == True) and initial_choice=="1":
            final_choice = "0"
        return final_choice
        
    def update_history(self,choice_made):
        self.history.append(choice_made)
        
    def update_score(self,binary_result,PayOff):
        if binary_result == "00":
            result = 0
        elif binary_result == "01":
            result = 1
        elif binary_result == "10":
            result = 2
        elif binary_result == "11":
            result = 3
        else :
            print("ERROR!!")
            exit()
        self.score+=PayOff[result]
        


# All Cheat
class CH(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        choice = "0"
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


# All Co-operate
class CO(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        choice = "1"
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


# Random Player
class R(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        choice = str(math.floor(np.random.uniform(0,1)/0.5))
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


# Copycat
class CC(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        if (len(opponent_history)==0):
            choice =  "1"
        else : 
            choice = opponent_history[-1]
            
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


# CopyKitten
class CK(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        if (len(opponent_history)==0) or (len(opponent_history)==1):
            choice =  "1"
        else : 
            if ((opponent_history[-1]=="0") and (opponent_history[-2]=="0")):
                choice = "0"
            else : 
                choice = "1"
        
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


# Grudger
class GR(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        if (len(opponent_history)==0):
            choice =  "1"
        elif ("0" in opponent_history) : 
            choice = "0"
        else :
            choice = "1"
            
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice

# Simpleton
class ST(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        if (len(opponent_history)==0):
            choice =  "1"
        else:
            if (opponent_history[-1] == "1"): 
                choice = own_history[-1]
            elif (opponent_history[-1] == "0") :
                if (own_history[-1] == "0"):
                    choice = "1"
                elif (own_history[-1] == "1"):
                    choice = "0"
        
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice

# Detective
class DE(Player):
    def __init__(self):
        Player.__init__(self)
        
    def make_choice(self,own_history,opponent_history,M):
        if (len(opponent_history)<=3):
            if (len(opponent_history)==1):
                choice = "0"
            else :
                choice = "1"
        elif ("0" in opponent_history[0:4]) : 
            choice = opponent_history[-1]
        else :
            choice = "0"
            
        final_choice = self.choice_after_mistake(choice,M)
        return final_choice


