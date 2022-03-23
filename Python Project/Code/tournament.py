
import math
import copy
import numpy as np

from matches import *

def ij_type_identifier(pop_dist, index_num):
    identifier_list = [0]
    for i in range(1,9):
        identifier_list.append(sum(pop_dist[0:i]))

    for j in range(0,8):
        if ((index_num>=identifier_list[j]) and (index_num<identifier_list[j+1])):
            player_index = j

    return player_index

def play_a_tournament(population_distribution,M,PR,RPM,PayOff):

    total_players = sum(population_distribution)

    score_matrix = np.zeros(total_players)

    for i in range(0,total_players):
        for j in range((i+1),total_players):

            player_index_1 = ij_type_identifier(population_distribution,i)
            player_index_2 = ij_type_identifier(population_distribution,j)
            match_score_card = match(player_index_1, player_index_2,M,RPM,PayOff)
            score_matrix[i] = score_matrix[i] + match_score_card[0]
            score_matrix[j] = score_matrix[j] + match_score_card[1]

    l2h_score_matrix = np.sort(score_matrix)
    lowest = l2h_score_matrix[0:PR]
    h2l_score_matrix = np.flip(l2h_score_matrix)
    highest = h2l_score_matrix[0:PR]

    new_population = copy.copy(population_distribution)

    for element in lowest :
        index = np.where(score_matrix==element)[0][0]
        player_population_index = ij_type_identifier(population_distribution, index)
        score_matrix[index] = 0 # to use when same score is to be eliminated twice
        new_population[player_population_index]-=1

    for element in highest : 
        index = np.where(score_matrix==element)[0][0]
        player_population_index = ij_type_identifier(population_distribution, index)
        new_population[player_population_index]+=1

    return new_population
    