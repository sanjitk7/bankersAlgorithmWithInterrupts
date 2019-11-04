#! /usr/bin/env python3
import csv
import pandas
import numpy as np

input_file = "./bankerintprocess.csv"

df = pandas.read_csv(input_file)

with open('graph.html', 'w') as fo:
    df.to_html(fo)

# ## colouring js
# style_text = '''
# <style>
# .market_make {
#     background-color: #FBB117;
# }
# </style>
# <script>
# var elements = document.getElementsByClassName('market_make');

# for(var i=0; i<elements.length; i++) {
#     elements[i].parentElement.setAttribute("bgcolor", "#FBB117");
# }
# </script>
# '''