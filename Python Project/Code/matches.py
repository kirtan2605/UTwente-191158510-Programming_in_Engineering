import numpy as np

from players import *

def calculate_scores(P1,P2,M,RPM,PayOff):

    for i in range(0,RPM):
        P1_choice = P1.make_choice(P1.history,P2.history,M)
        P2_choice = P2.make_choice(P2.history,P1.history,M)
        P1.update_history(P1_choice)
        P2.update_history(P2_choice)
        result_P1 = P1_choice + P2_choice
        result_P2 = P2_choice + P1_choice
        P1.update_score(result_P1,PayOff)
        P2.update_score(result_P2,PayOff)
    
    score_card = []
    score_card.append(P1.score)
    score_card.append(P2.score)

    return score_card


def match(player_index__1, player_index__2,M,RPM, PayOff):

    Players = {"CH" : 0, "CO" : 1, "R" : 2, "CC" : 3, "CK" : 4, "GR" : 5, "ST" : 6, "DE" : 7}
    Players_index = {0 : "CH", 1 : "CO", 2 : "R", 3 : "CC", 4 : "CK", 5 : "GR", 6 : "ST", 7 : "DE"}

    player_class_1 = Players_index[player_index__1] + "()"
    player_class_2 = Players_index[player_index__2] + "()"

    P1 = eval(player_class_1)
    P2 = eval(player_class_2)

    scores = calculate_scores(P1,P2,M,RPM,PayOff)

    del P1
    del P2

    return scores
