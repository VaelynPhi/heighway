var graphtypes() = {
 'histogram' : histogram;
 'normaldistribution' : normaldistribution;
['linearregression',linearregression],
['scatterplot',scatterplot],
];

function initstatgraph(){
 var graph = document.getElementsByTagName('statgraph')[0];
 var type = graph.getAttribute('type');
 var data = graph.getAttribute('data').split(' ');
 
}

function histogram(){
 alert('I am not a histogram.');
}