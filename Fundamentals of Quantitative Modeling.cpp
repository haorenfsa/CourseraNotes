expect{
    terms of modeling
    application
    process of it
    character of business and modeling
    value and limitation
    provide a set of found 
}

res{
    excel
    google sheet
    R
    math review:
    E-book: Business Math for MBAs
    mathmba.selz.com/
}

module 1{
    content{
        eg and uses of models 
        key step
        vocabulary
        math functions
          linear, power, exponential,log
    }
     
    wheat is a model{
        formal [description] of business process
        involves: math equaltion random var(simulation)
        assumptions + simplification
        implement: program, spreadsheet
        
         eg{
            jewelery business
            price of a diamond  - weight (linear)
            demand and price
        }
    }
    how models are used{
        calculate single output
        forecasting - resource planning
        optimization
        ranking and targeting  (limited res)
        waht-if scenarios
        interpreting coefficent
        access how sensitive the model is to key assumptions
    }
    
    benefits of modeling{
        id gap in current understanding
        make assumptions explicit
        a well-defined description of the business process
        create an institutional(制度化的) memory
        a decision support tool
        serendipitous(偶然) insight generator
    }
    
    key process{
        workflow{
            graph
            id and define inputs and outputs;  define scope;
            formulate model;
            (key)sensitivity analysis; validate forecast;
            if(fit for purpose)
                goto implement;
            else
                go back;
        }
        if dont work{
            every infomative;
            often meanning sth u dont notice before;
            modeling is contious and evolutionary process
            id the weaknesses and limitations and iterate the flow to overcome them
        }
        
    }
    
    lexicon(词库){
        empirical - theoretical
        eg{
            assume market is effcient
            data driven or theoretical driven
        }
        deterministic vs probabilistic/stochastic{
            same given I, ideal,fixed O
            lottory, uncertain
        }
        discrete vs continuous variable{
            digital, analog
            dump and idistinct; smoother,infinite(but human eye resolution is limited);
            
        }
        static and dynamic model{
            a single snapshot of the business process;
            move from state to state
        }
    }
    
    Key mathematical functions{
        x - y changing style
        
        linear{
            intercept b, slope m(fixed)
            y = mx + b
            eg{
                time salary
                3000 - 6500 - 9000
            }
            
            key: is it reasonable?
        }
        power{
            y=[a*]x^m [+ b]
            base: x, exponent: m
            relative - relative
            (x change 1 percent, y will change (1.01^m) percent)
        }
        exponential{
            growing gradually fast
            decresing gradually slow
            y = e^mx ,e=2.71828...
            absolute - relative 
            if |m| <=0.2, for every 1 unit in x, about 100m%change in y
        }
        log (most often){
            increasing at a decreasing way
            exhibit diminishing returns to scale
            relative - absolute
            constant proportionate change in x with the same absolute change in y
            
            b: base of the logarithm
            most often: e, natural log
            undoes function: 
            x = - ln e^x
            x = - e^ lnx
            ln as log
        }
        
    }
    sum{
        
    }
}

// linear model intro, and optm
module 2{
    content{
        linear models
        growth and decay in discrete or continuous time
        classical optimization
    }
    deterministic model feature{
        no random var
        downside: hard to assess uncertainty in outputs
    }
    linear{
        slope is constant
    }
    linear programming{
        LP   solve certain optimization problems
        often used in Excel or other spreadsheet
    }
    
    Growth in discrete time{
        proportionate / additive | growth
        simple/compound interest
    }
    constant proportionate growth{
        the sum geometric series fomula
        等差求和
    }
    Present and Future Value{
        continuous compound
        e 符合无穷细分复利模型
    }
    optimization{
        求函数max
        visualize
    }
}

Probabilistic model{
    probabilitiy distributions: means（均值）, variances（方差） and std deviation（偏差）
    random var: Bernoulli Binomial and Normal
    incorparate uncertainty explicitly in model
    
    probabilistic egs{
        oil price - airline cost
    }
}