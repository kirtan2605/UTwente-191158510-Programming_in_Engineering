import pandas as pd
import matplotlib.pyplot as plt

def display_result(input_dataframe):

    # https://queirozf.com/entries/pandas-dataframe-plot-examples-with-matplotlib-pyplot

    players_type = ['CH','CO','R','CC','CK','GR','ST','DE']
    ax = plt.gca()
    for element in players_type:
        input_dataframe.plot(kind='line', y = element,linestyle = '-',marker=',',ax=ax)

    plt.savefig("result.pdf", format="pdf", bbox_inches="tight")
    plt.xlabel('No. of Tournaments')
    plt.ylabel('Number of Players')
    plt.show()

    return 0