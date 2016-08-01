# class 1: intro #
## AI Dream ##
## New computer capability ##
### examples ###


- database miniing

	web click;
	medical records;
	bilology;

- Applications cant progam by hand
	
	Autonomous helicop
	NLP
	computer vision
	
- sel-comtomizing program
- Understading human learning



# class 2: supervised learning #
### housing price preditction ###
function parameter to be determined

### concept ###
so supervised learning is that
we are given a dataset ,and given right answer to every data

### regression problem ###
deal with continous valued output
(or countless discrete value)
cf: classification problem is discrete

### another example of Breast Cancer ###
how to estimate the chance of malignant
it may be determined by many featrues, and maybe infinite.

### how to deal with infinite feature ###
an Algorithm called Suport Vector Machine 


# class3 Unsupervised learning #
the resault is not labeled right or wrong

	clustering algorithm
	eg: news.google.com cluster identify the news type
	eg2: genes recogonize
	eg3:social network analysis
	eg4:market segmentation
	eg5:astronomical data analysis

### cocktail party problem ###
1.
	2people	2microphone in a room
	input to an algorithm
2.
	1 people in a noisy place with 2microphone

canbe done in 1 line!

	[W,s,v] = svd ((repmat(sum(x.*x,1), size(x,1),1).*x) *x');

### "Octave" the open source program env(matlab is as fine) ###

most ML Algos are first prototype in Octave in Silicon Valley which is very fast

svd function stands for: singular value decompositon 
which is a linear algebra routine built in Octave

### about quiz ###
makes me think that is there a rule to decide whether it should be implement in unsurpervised learning?
answer:
by whether u got data with correct answer or not.


# chapter: model and cost function #
## Model Representation ##

#### concept: training set ####

	m for number of training set examples
	x for input
	y for output
	(x,y) one example
	(x(i),y(i)) for the i-th example

#### concept: hypothesis ####

	input - hypothesis - output

how to represent h?

	h(ceta)(x) = ceta0 + ceta1x
	shorthand: h(x);
	ceta is called parameter

Model Name :linear regression with 1 var 
or Univariate linear regression
## cost function ##

	choose ceta0 ceta1 so that h(x) is close to y

-> 1/2m sum(m,i, minimize( h(x)(i) - y(i) )^2 )

	J(ceta0,ceta1)
	called cost function
	also squared error function
	in chinese 代价函数/方差函数

we need to find a algorithm to auto calculate the J func
and it should work when there are more parameters.