immediatenotes{
	需要按时转到别的地方保持短小：
	-----------------------
	代码前面把你要干什么说清楚
	
	新公积金账户{
		身份证和银行卡
	}

	
	用流记录工作进程，晚上要处理流的遗留问题
	总结一下接下来的工作和优先度，评估潜在工作量
	
	软件知识能力的分类，如设计
	
}
daily{
	dailycheck 3/21
	每天早上开工前用一个potato做计划；结束时用一个做总结，总结是处理今天note的更新	0/21
	晚上回家后需要先检查明天要带的东西	0/21
	exercise{
		even /oddoreven
		chest 50/100
		abdomen 25/100
		leg front 0/100
		*leg back 50/100
	}
	
}

daily notes{
	评估，计划{
		config的工作量大约2h*10*2 = 40h,测试时间大概也是40h,但是今晚阅读要搞定
	}
	ATS串讲
	事件的思维导图
}

ATS todo{
	
	前向代理不工作？
	监察工具不能用？
	配置
	插件
	大概结构
		ATS doc readplan:
		reverse proxy
		plugins -stable
		logging -briefly
		monitoring - briefly
		tuning
		config files
		--
		developer part
}

nginx{
	【setup env】openresty + luarocks +其它工具
	
	【REF】！nginx在openresty的大量资料
	
	location 详细
	http://blog.csdn.net/xy2204/article/details/47749405
	
	rewrite 各种选项
	http://www.76ku.cc:90/articles/archives/317
	
	关于模拟：
	静态：
	主机用多端口，访问L1的nginx前端，前端upstram给后端L2的TS缓存，TS连接L3的nginx源服务器。
	L3的服务器源文件定期更新
	上面是总的层级，层数太多，测试应该一层一层测
	压力情况，处理速度，出错率
	
	日志工具{
		GoAccess
	}
	
	平滑升级http://zachary-guo.iteye.com/blog/1358312
	
	curl要开启长连接
	upstream 1.10默认短连接需要proxy_http_version 1.1;
	还要keepalive 16;16为一个worker中最多允许的个数;?
	
	优化参数参考
	
	start progress{		
		时间、正则、错误日志、ssl等初始化
		读入命令行参数
		OS相关初始化
		读入并解析配置
		核心模块初始化
		创建各种暂时文件和目录
		创建共享内存
		打开listen的端口
		所有模块初始化
		启动worker进程

	}
	
	important notes{
		ngx_str_t not end with '\0';
		所以我们在调用系统api时，就不能直接传入str->data了。
		此时，通常的做法是创建一段str->len + 1大小的内存，然后copy字符串，最后一个字节置为’\0’。
		
	}
	
	Basic Functionality
	{
    Web server – Configuring virtual servers and locations, using variables, rewriting URIs, and customizing error pages
    Serving static content – Setting the root directory for requested content, and creating ordered lists of files to serve if the original index file or URI does not exist
    Reverse proxy – Proxying requests to HTTP, FastCGI, uwsgi, SCGI, and memcached servers; controlling proxied request headers; and buffering of responses from proxied servers
    Compression and decompression – Compressing responses on the fly to minimize use of network bandwidth
    Web content cache – Caching static and dynamic content from proxied servers
	}
	模型特点
	{
		master worker
		异步非阻塞；减少了切换带来的资源浪费
		优化：进程要绑定CPU核；字符串多个合并成整型比较等。
		
		对于一个基本的web 服务器来说，事件通常有三种类型，
		网络事件(IO)、信号、定时器。
	}
	config file
	{
		 default /etc/nginx/nginx.conf
	}
	basic using{
		simple http server config
		simple proxy server config
		-proxy fastcgi
	}
	
	reverse proxy{
		反向代理（Reverse Proxy）方式是指以代理服务器来接受internet上的连接请求，
		然后将请求转发给内部网络上的服务器，并将从服务器上得到的结果返回给internet上请求连接的客户端，
		此时代理服务器对外就表现为一个反向代理服务器。
		反向代理还可以为后端的多台服务器提供负载平衡，或为后端较慢的服务器提供缓冲服务。
		relation with CDN{
			通过在网络各处放置反向代理节点服务器所构成的在现有的互联网基础之上的一层智能虚拟网络，CDN系统能够实时地根据网络流量和各节点的连接、负载状况以及到用户的距离和响应时间等综合信息将用户的请求重新导向离用户最近的服务节点上。其目的是使用户可就近取得所需内容，解决 Internet网络拥挤的状况，提高用户访问网站的响应速度。
		}
	}
	
	ADMIN GUIDE{
		configure as Web server
		{
			 uses the Perl syntax for regular expressions{
				 A regular expression is preceded with the tilde (~) for case-sensitive matching, or the tilde-asterisk (~*) for case-insensitive matching
			 }
			 
			 config locations
			 
			 using variables{
				 $varname
				 define custom variables using the set, map, and geo
				 set $variable value;
				 
				 predefined variables{
					 core HTTP variables
					 Most variables are computed at runtime and contain information related to a specific request
					  $remote_addr contains the client IP address 
					  $uri holds the current URI value.
				 }
			 }
			 
			 Returning Specific Status Codes{
				 eg:
				 return 404;
				 The optional second parameter can be the URL of a redirect (for codes 301, 302, 303, and 307) or the text to return in the response body. 
				 return 301 http://www.example.com/moved/here;
			 }
			 
			 Rewriting URIs in Requests{
				 eg:
					rewrite ^(/download/.*)/media/(.*)\..*$ $1/mp3/$2.mp3 last;
					rewrite ^(/download/.*)/audio/(.*)\..*$ $1/mp3/$2.ra  last;
					return  403;
				last – Stops execution of the rewrite directives in the current server or location context, but NGINX Plus searches for locations that match the rewritten URI, and any rewrite directives in the new location are applied (meaning the URI can be changed again).
				break – Like the break directive, stops processing of rewrite directives in the current context and cancels the search for locations that match the new URI. The rewrite directives in the new location are not executed.

			 }
			 
			 Rewriting HTTP Responses{
				 sub_filter{
					  	sub_filter_once on/off: Indicates whether to look for each string to replace once or repeatedly. 
				 }
			 }
			 
			 Handling Errors{
				 error_page 404 /404.html;
				 when page move permanently
				 location /old/path.html {
					error_page 404 =301 http:/example.com/new/path.html;
				 }
			}
		}
		
		Serving Static Content{
			If a request ends with a slash, tries to find an index file in the directory
			try_files:
				try_files $uri /images/default.gif;
				try_files $uri $uri/ $uri.html =404;
				
				location / {
					try_files $uri $uri/ @backend;
				}
				location @backend {
					proxy_pass http://backend.example.com;
				}
			geo{
				option:
				delete;default;include;proxy;proxy_recursive;ranges
				
				ranges;
				ip1-ip2 XX;
			}
		}
		
		Optimizing NGINX Speed{
			Loading speed is a crucial factor
			By default, NGINX handles file transmission itself and copies the file into the buffer before sending it. 
			sendfile:
				sendfile           on;
				sendfile_max_chunk 1m;//to prevent one fast connection to entirely occupy the worker process
				
				sendfile   on;
				tcp_nopush on;//enable NGINX to send HTTP response headers in one packet right after the chunk of data has been obtained by sendfile
				
			
			tcp_nodelay       on;//By default, the tcp_nodelay directive is set to on which means that the Nagle’s algorithm is disabled. The option is used only for keepalive connections:
			keepalive_timeout 65;
			
			Optimizing the Backlog Queue{
			incoming connections in high load situation
			Measuring the Listen Queue：netstat -tnlp
			solusion Linux OS:
				Increase the value of the net.core.somaxconn key from its default value (128) to the value high enough to be able to handle a high burst of traffic:
				sudo sysctl -w net.core.somaxconn=4096
				vi   /etc/sysctl.conf 
				->add:net.core.somaxconn = 4096->savefile
			Nginx: //If you set the somaxconn key to a value greater than 512, change the backlog parameter of the NGINX listen directive to match:
				server {
					listen 80 backlog 4096;
					# The rest of server configuration
				}
		}
		
		
	}
	
		
	}
}

！串讲方式{
		简介{
			解决的问题
			架构
			简单实用
		}
		工程对外应用上{
			架构、部署、配置、扩展、调试
		}
		内部使用上{
			api
			基本数据类型
		}
		技术上{
			业务逻辑->问题 +
			对应解决数据结构+api
			或对应解决特殊算法
			+实际代码实现技巧
		}
	越往下越细节
	
}

//note date
QA{
    进程状态 内存情况{

        PID：进程的ID
        USER：进程所有者
        PR：进程的优先级别，越小越优先被执行
        NInice：值
        VIRT：进程占用的虚拟内存
        RES：进程占用的物理内存
        SHR：进程使用的共享内存
        S：进程的状态。S表示休眠，R表示正在运行，Z表示僵死状态，N表示该进程优先值为负数
        %CPU：进程占用CPU的使用率
        %MEM：进程使用的物理内存和总内存的百分比
        TIME+：该进程启动后占用的总的CPU时间，即占用CPU使用时间的累加值。
        COMMAND：进程启动命令名称

        1：使用 ps -ef|grep xxx 命令查找需要查看的进程，xxx是进程名字

        2：top -p pid 查看程序的情况 

        3：ps -aux | grep process_name

        4：cat /proc/pid/status 
        这里会打印出当前进程详细的情况，其中，内存是 VmRSS。 
        注：pid是要替换成一个id数字的。

    }
    
     tc{
         tc qdisc add dev eth0 root netem delay 100ms
     }
    
	malloc() : smallbin double linked list corrupted 
	{
		问题应该出在问题点之前的地方，破坏了堆内存。
		最后查到是double free的问题。
		要注意free之后指针未必为NULL
	}
	
	GLIBCXX_ not found 问题
	{
		 strings /usr/lib64/libstdc++.so.6|grep GLIBCXX ，查看
		 到gcc编译时的目录下面找到文件：libstdc++.so.6.0.18,替换
	}
	
	
	【文档写法】
	http://www.cnblogs.com/trendline/articles/how-to-create-design-doc.html
	
	kernel panic:initramfs problem
	https://communities.vmware.com/thread/456893
	
	chkconfig
	开机启动项
	
	iptable -2{
		开启3306端口并保存

		/sbin/iptables -I INPUT -p tcp --dport 3306 -j ACCEPT

		/etc/rc.d/init.d/iptables save

	}
	
	gcc include目录
	`g++ -print-prog-name=cc1plus` -v
	
	线程查看{
		1、top -H
		手册中说：-H : Threads toggle
		加上这个选项启动top，top一行显示一个线程。否则，它一行显示一个进程。
		2、ps xH
		手册中说：H Show threads as if they were processes
		这样可以查看所有存在的线程。
		3、ps -mp <PID>
		手册中说：m Show threads after processes
		这样可以查看一个进程起的线程数。
		更多详尽的解释还可以man ps，man top。
	}
	【Q】wget
		wget是一个从网络上自动下载文件的自由工具，支持通过HTTP、HTTPS、FTP三个最常见的TCP/IP协议下载，并可以使用HTTP代理。wget名称的由来是“World Wide Web”与“get”的结合。
	【Q】nginx配置文件变量作用域和生存周期
	【Q】Traffic Control会导致tcpdump的解析出问题
	【Q】盗链的场景有哪些？防盗链的基本目的和原理？
	URL鉴权防盗链
	nginx_lua{
		ngx_lua提供了与Nginx交互的很多的API，对于开发人员来说只需要学习这些API就可以进行功能开发，
		而对于开发web应用来说，如果接触过Servlet的话，其开发和Servlet类似，无外乎就是知道接收请求、参数解析、功能处理、返回响应这几步的API是什么样子的。
		
		我们可以使用OpenResty来搭建开发环境，OpenResty将Nginx核心、LuaJIT、许多有用的Lua库和Nginx第三方模块打包在一起；
	}
		luaBasic.lua语法说明
	【QA】闭包？LUA:当一个函数内部嵌套另一个函数定义时，内部的函数体可以访问外部的函数的局部变量，这种特征在lua中我们称作词法定界。
		使用场景？setmetatable？
		
	【QA】lua的特点，为什么使用它{
		Lua 最大的好处就是小，绝对的小，可以嵌入任何程序而我们几乎可以忽略为此增加的大小。这门语言的功能基本是完备的。
		它没有处理 UTF-8 的逻辑。所有的字符串当作字节流处理。
		
		Lua本来就是嵌入式，
		那么用途就是粘合粘合粘合。
		本身很好的与C/C++交互效果非常棒。
	}
	
	【Q】cloudflare company
	
	【QA】redis,Twemproxy,  Memcached
	redis作为key-value缓存，而且提供了丰富的数据结果如set、list、map等，可以实现很多复杂的功能；但是Redis本身主要用作内存缓存
	Twemproxy
	是一个Redis/Memcached代理中间件，可以实现诸如分片逻辑、HashTag、减少连接数等功能；
	尤其在有大量应用服务器的场景下Twemproxy的角色就凸显了，能有效减少连接数。
	
	【QA】默认动态库地址/etc/ld.so.conf
	
	strace使用？
	time/strace追踪运行时间
	
	open和unlink的开销？ 可以写程序测时间
	unlink是什么？ 断链，如果最后一个，且没有正在使用的进程，会删除它
	
	GO Nginx在处理高并发能力上非常出色，而go作为新时代互联网语言，在设计之初就为实现高并发。ngx_lua由Nginx来处理网络事件，并使用协程来实现非阻塞，从而实现高并发。 go语言级别提供非阻塞的api，同样使用协程来提供高并发处理。
	
	操作系统{
		父子进程通过映射共享代码段。
		动态库：代码映射后共享，数据不共享。
	}
	
	cosi 的原理
	
	iptable{
		vi /etc/sysconfig/iptables 
		或 +保存的 iptables -I INPUT -p tcp --dport 8000 -j ACCEPT
		/sbin/iptables -L -n
		service iptables restart
		http://www.centoscn.com/CentOS/config/2015/0915/6172.html
		http://www.jb51.net/os/RedHat/68744.html
		http://www.linuxidc.com/Linux/2013-07/87045p2.htm
	]
	
	functional Modules: transform conten ok	
	modules: phase handlers ok
	nginx具体使用何种事件处理模块，这依赖于具体的操作系统和编译选项。???
	
	在对upstream做load balance的时候有时需要worker之间共享一个zone，是不是会引入进程同步问题？会影响速度？
	http2.0
	
	
	nginx 内存分配应该怎么确定用什么api合适？
	Ketama Consistent Hash
	
	*虚拟化技术的优势？硬件抽象共享 - 和云的关系？
	*协程？？
	127.0.0.1回环
	散列表 -hash
	*静态二叉查找树
	*volatile
	*多次回调问题，如建立连接时 - 不会 ，因为是单线程处理运作
	server选取会受到头影响吗？
	*nginx可继续学习：动态页面、有表格输入的处理；
	两次重定向的例子？
	页游服务器的实现？
	
	*简单防爬
	
	*移动网络需要信令保活？
	
	查看被开启的端口号？netstat -tnap
	
	自动安装依赖包的一般位置：./contrib/download_prerequisites　
	
	惊群问题和backlog{
		其结 果就是每当资源可用，所有的进程/线程都来竞争资源，造成的后果：
		1）系统对用户进程/线程频繁的做无效的调度、上下文切换，系统系能大打折扣。
		2）为了确保只有一个线程得到资源，用户必须对资源操作进行加锁保护，进一步加大了系统开销。
		accept - 多线程阻塞时内核中只会唤醒1个
		
		SYN包的回复是底层自动完成的，有SYN队列和ACCEPT队列，握手完成前在SYN队列，完成后再ACCEPT队列
		tcp的backlog = SYN + ACCEPT
		超时：网络超时、队列满
	}
	
	TCP区分连接？TCB: Transmission Control Block 来唯一识别一个TCP连接，用五元组来识别一个TCP连接太不方便。
	{
		最初TCP进程在用户进程调用socket的时候，建立了一个映射关系，五元组 <---->session ID (TCB):


[IP Source Address + IP Destination + Source Port +Destination Port+Protocol ] <--->session ID (TCB)

作者：车小胖
链接：https://www.zhihu.com/question/31079440/answer/106497081
来源：知乎
著作权归作者所有，转载请联系作者获得授权。
	}
	
	TCP连、断的握手{
		断开四次握手的原因
		主动的写关闭和被动的读关闭；
		最后主动发起方关闭前，等一个MSL的时间
	}
	
	HTTP{
		
		①　请求方法 URI 协议/版本
		②　请求头(Request Header)
		③　请求正文
		下面是一个HTTP请求的例子：

		GET/sample.Jsp HTTP/1.1
		Accept:image/gif.image/jpeg,*/*    ;多余格式 */
		Accept-Language:zh-cn
		Connection:Keep-Alive
		Host:localhost
		User-Agent:Mozila/4.0(compatible;MSIE5.01;Window NT5.0)
		Accept-Encoding:gzip,deflate
		
		username=jinqiao&password=1234
		
		pipeline{
			http 1.1规定服务器端必须按相同的顺序返回响应
		}
		
		keep-alive{
			firefox为例，用TCP心跳实现，默认10秒一次探测，默认保持60秒，然后4次握手断开
			1.1默认开启
			优点：避免多次请求的开销、可以pipeline形式发请求、连续请求延时减少了、请求错误可以报告而不用直接断开连接，有益于Http设计
			问题：不能用EOF来判断请求/响应结束，那怎么判断？方法：使用头部的Conent-Length(静态，表示实体长度，而不是实际传输长度，有编码时两者不同)；
			"Transfer-Encoding: chunked"；(动态，一边处理一边发送)
		}
		HTTP1.1支持7种请求方法 GET、POST、HEAD、OPTIONS、PUT、DELETE和TARCE。在Internet应用中，最常用的方法是GET和POST
		请求头和请求正文之间是一个空行
		GET方法{
			默认，表单作为url一部分，简单编码
		}
		POST{
			它主要是向Web服务器提交表单数据，尤其是大批量的数据。
		}
		从编程的角度来讲，如果用户通过GET方法提交数据，则数据存放在QUERY＿STRING环境变量中，
		而POST方法提交的数据则可以从标准输入流中获取
	}
	
	TCP心跳保活{
		TCP默认自带心跳，但是时间长
		TCP keep-alive / ACK
		TCP_KEEPCNT 覆盖  tcp_keepalive_probes，默认9（次）
		TCP_KEEPIDLE 覆盖 tcp_keepalive_time，默认7200（秒）
		TCP_KEEPINTVL 覆盖 tcp_keepalive_intvl，默认75（秒
	}
	
	CNAME{
		DNS的IP记录类型，
		A记录网站； MX邮件路由记录
		TTL缓存时间
		CNAME别名记录，可以有两种解释
	}
	
	CDN基本流程{
		L4/7交换机 http://dannyswallow.blog.51cto.com/5062777/1754809
		ATS/CDN blog
		http://blog.csdn.net/tao_627/article/details/48223565
		简单工作过程
		http://www.cnblogs.com/shytong/p/5456698.html
	}
	
	NGX常见日志错误 http://blog.csdn.net/gaojinshan/article/details/38399347
	
	IO2{
		阻塞非阻塞，异步http://www.cnblogs.com/Anker/p/3254269.html
		select/poll/epoll
		http://www.cnblogs.com/lianzhilei/p/6029100.html
		
		异步:
		非阻塞 :阻塞主要原因来自于缓冲区慢
		http://www.cnblogs.com/inevermore/p/4046283.html
	}
	
	c内嵌汇编 __asm__{
		http://blog.csdn.net/robbie1314/article/details/6329329
	}
	
	寄存器{
		http://www.cnblogs.com/qq78292959/archive/2012/07/20/2600865.html
	}
	
	Nginx+CGI服务器搭建{
		一般常见的网站，采用apache+tomcat+数据库
		或是Ngix+tomcat+数据库这三层物理架构；如果是大型网站应用，上面还会有一层硬件负载均衡F5。
		php http://blog.csdn.net/dyllove98/article/details/41120789
		C
		http://blog.csdn.net/allenlinrui/article/details/19419721
		http://blog.chinaunix.net/uid-11344913-id-3192736.html
	}
	
	apache nginx比较{
		http://www.cnblogs.com/huangye-dream/p/3550328.html
	}
	
	powershell{
		Set-ExecutionPolicy -Scope CurrentUser REMOTESIGNED
	}
	
	浏览器收到所有脚本，在浏览器端执行，所以用户可以看到所有前端代码
	
	内核缓冲区{
		标准IO缓冲区
		http://blog.chinaunix.net/uid-26833883-id-3198114.html
		TCP input流长于内核缓冲区怎么处理？ ->内核需要多次读取
		每个数据链路都有一个数据队列，如果该队列已满，那么新到的分组将被丢弃，并沿协议栈向上返回一个错误：从数据链路到IP，在从IP到TCP。TCP将注意到这个错误，并在以后某个时候重传相应的分节。应用程序不知道这种暂时的情况。
	}
	
	getrlimit()/setrlimit(){ //abbr. resource limit
		调用getrlimit()或者setrlimit()来操作指定资源的操作上限。
		资源限制是一对值：一个指定了当前（软）限制，另一个则代表一个最大（硬）限制。
		软限制能够被一个进程改变，只要保证它不大于硬限制。
		一个进程能够（不能够撤回的）降低它的硬件限制，前提是大于等于软限制。
		http://blog.csdn.net/stormkey/article/details/5890512
	}
	
	buf_t操作{
		创建
		http://www.tuicool.com/articles/r6ZnUfF
	}
	
	*原子操作
	
	*iovec{
		散布读和聚集写
	}
	
	*iocp{
		IOCP（I/O Completion Port）,常称I/O完成端口。 IOCP模型属于一种通讯模型，适用于(能控制并发执行的)高负载服务器的一个技术。
		重叠IO[overlapped I/O]是Win32的一项技术，你可以要求操作系统为你传送数据，并且在传送完毕时通知你。这也就是[完成]的含义。
		操作系统内部正是以线程来完成overlapped I/O。
		完成端口中所谓的[端口]并不是我们在TCP/IP中所提到的端口，可以说是完全没有关系。IOCP只不过是用来进行读写操作，和文件I/O倒是有些类似。
		① 帮助维持重复使用的内存池。(与重叠I/O技术有关)
	　　② 去除删除线程创建/终结负担。
	　　③ 利于管理，分配线程，控制并发，最小化的线程上下文切换。
	　　④ 优化线程调度，提高CPU和内存缓冲的命中率。
	}
	
	MIME{
		MIME(Multipurpose Internet Mail Extensions)多用途互联网邮件扩展类型。
		是设定某种扩展名的文件用一种应用程序来打开的方式类型，当该扩展名文件被访问的时候，浏览器会自动使用指定应用程序来打开。
	}
	
	sizeof{
		c99标准前 
		sizeof的计算发生在编译时刻，所以它可以被当作常量表达式使用
		指针：32位为 4， 64位 为 8
	}
	
	spin lock: 自旋锁{
		等待进程会自旋，占用CPU，但是响应解锁速度更快。
		适合处理时间短的情况。
		资源在中断上下文访问，必须用自旋锁。
		自旋锁只有在内核克抢占或多处理器情况下需要
	}
	
	on-the-fly{
		传输过程中
	}
	
	内外网{
		 内网的计算机以NAT（网络地址转换）协议，通过一个公共的网关访问Internet
		 使用NAT协议，局域网内的计算机可以访问Internet上的计算机，但Internet上的计算机无法访问局域网内的计算机。
		*NAT{
			PPP
		}
		NAPT Network Address Port Translation{
			可将多个内部地址映射为一个合法公网地址，但以不同的协议端口号与不同的内部地址相对应
			<内部地址+内部端口>与<外部地址+外部端口>之间的转换
		}
	}
	
	CIDR{
		无类别域间路由，Classless Inter-Domain Routing
		是一个在Internet上创建附加地址的方法，这些地址提供给服务提供商（ISP），再由ISP分配给客户。
		 CIDR采用8~30位可变网络ID，而不是A-B-C类网络ID所用的固定的8、16和24位。
	}
	
	cookie{
		无论是get还是post请求，http请求头都会带着cookie。
		Set－Cookie: NAME=VALUE；Expires=DATE；Path=PATH；Domain=DOMAIN_NAME；SECURE
		Cookie 是一小段文本信息，伴随着用户请求和页面在 Web 服务器和浏览器之间传递。用户每次访问站点时，Web 应用程序都可以读取 Cookie 包含的信息。
		指某些网站为了辨别用户身份、进行 session 跟踪而储存在用户本地终端上的数据（通常经过加密）。
		定义于 RFC2109 和 2965 中的都已废弃，最新取代的规范是 RFC6265
		一旦用户从该网站或服务器退出，Cookie 可存储在用户本地的硬盘上 （此种 Cookies 称作 Persistent Cookies）
		通常情况下，当用户结束浏览器会话时，系统将终止所有的 Cookie。
		Cookie 必须在 HTML 文件的内容输出之前设置；
		不同的浏览器 (Netscape Navigator、Internet Explorer) 对 Cookie 的处理不一致，
		使用时一定要考虑；客户端用户如果设置禁止 Cookie，则 Cookie 不能建立。 
		并且在客户端，一个浏览器能创建的 Cookie 数量最多为 300 个，并且每个不能超过 4KB，
		每个 Web 站点能设置的 Cookie 总数不能超过 20 个
	}
	
	route{
		Route就是用来显示、人工添加和修改路由表项目的。
		大多数主机一般都是驻留在只连接一台路由器的网段上。
		由于只有一台路由器，因此不存在使用哪一台路由器将数据包发表到远程计算机上去的问题，
		该路由器的IP地址可作为该网段上所有计算机的缺省网关来输入。 
		但是，当网络上拥有两个或多个路由器时，你就不一定想只依赖缺省网关了。
		实际上你可能想让你的某些远程IP地址通过某个特定的路由器来传递，
		而其他的远程IP则通过另一个路由器来传递。
	}
	
	状态机state machine{
		http://blog.csdn.net/eager7/article/details/8517827/
		状态迁移图（STD）
	}
	
	学习的目标好像是要 配置Nginx 并 开发Nginx自定义模块 以达到一定的功能
	
	颠簸（thrashing）是不作处理的计算机活动，通常是因为内存或其他资源耗尽或有限而无法完成所要执行的操作。
	
	multiplexing{
		多路复用还可以指单线程多连接
		多路复用，时分/频分 一条信道传多路信息 ；
	}
	
	SSI{
		Server Side Includes 服务器端嵌入
		SSI就是在HTML文件中，可以通过注释行调用的命令或指针。SSI具有强大的功能，只要使用一条简单的SSI 命令就可以实现整个网站的内容更新，时间和日期的动态显示，以及执行shell和CGI脚本程序等复杂的功能。
		感觉像是一种动态网页技术？
		用途
		1、显示服务器端环境变量<#echo>
		2、将文本内容直接插入到文档中<#include>
		3、显示WEB文档相关信息<#flastmod #fsize> （如文件制作日期/大小等）
		4、直接执行服务器上的各种程序<#exec>(如CGI或其他可执行程序）
		5、设置SSI信息显示格式<#config>；（如文件制作日期/大小显示方式） 高级SSI<XSSI>；可设置变量使用if条件语句。[2]  
	}
	
	ABI&API{
		API定义了源代码和库之间的接口，因此同样的代码可以在支持这个API的任何系统中编译
		然而ABI允许编译好的目标代码在使用兼容ABI的系统中无需改动就能运行
		ABI涵盖了各种细节,而API只要编译后能用即可
	}
	
	IO{
		在Linux/UNIX 下，有下面这五种I/O 操作方式：
		1.阻塞 I/O
		2.非阻塞 I/O
		3.I/O 多路复用
		4.信号驱动 I/O（SIGIO）
		5.异步 I/O
	}
	
	STDIN_FILENO {
		/* Standard file descriptors.  */
		#define STDIN_FILENO    0       /* Standard input.  */
		#define STDOUT_FILENO   1       /* Standard output.  */
		#define STDERR_FILENO   2       /* Standard error output.  */
	}
	
	memory pool/slab{
		pool内存池是在真正使用内存之前，先申请分配一定数量的、大小相等(一般情况下)的内存块留作备用。
		主要防止碎片化。
		
		slab{
			一种针对小内存区的内存分配机制 
			与传统的内存管理模式相比， slab 缓存分配器提供了很多优点。
			1、内核通常依赖于对小对象的分配，它们会在系统生命周期内进行无数次分配。
			2、slab 缓存分配器通过对类似大小的对象进行缓存而提供这种功能，从而避免了常见的碎片问题。
			3、slab 分配器还支持通用对象的初始化，从而避免了为同一目的而对一个对象重复进行初始化。
			4、slab 分配器还可以支持硬件缓存对齐和着色，这允许不同缓存中的对象占用相同的缓存行，从而提高缓存的利用率并获得更好的性能。
		}
	}

	异步非阻塞->select/poll/epoll ; kqueue
	int select( int nfds, fd_set FAR* readfds,　fd_set * writefds, fd_set * exceptfds,　const struct timeval * timeout){
		nfds：是一个整数值，是指集合中所有文件描述符的范围，即所有文件描述符的最大值加1，不能错！在Windows中这个参数的值无所谓，可以设置不正确。
		readfds：（可选）指针，指向一组等待可读性检查的套接口。
		writefds：（可选）指针，指向一组等待可写性检查的套接口。
		exceptfds：（可选）指针，指向一组等待错误检查的套接口。
		timeout：select()最多等待时间，对阻塞操作则为NULL。
		
		FD CONTROLS{
			在socket.h头文件中共定义了四个宏来操作描述字集。
			FD_SETSIZE变量用于确定一个集合中最多有多少描述字（FD_SETSIZE缺省值为64，可在包含socket.h前用#define FD_SETSIZE来改变该值）。
			对于内部表示，fd_set被表示成一个套接口的队列，最后一个有效元素的后续元素为INVAL_SOCKET。
			宏为：
			FD_CLR(s,*set)：从集合set中删除描述字s。
			FD_ISSET(s,*set)：若s为集合中一员，非零；否则为零。
			FD_SET(s,*set)：向集合添加描述字s。
			FD_ZERO(*set)：将set初始化为空集NULL。
		}
	}
	poll -> epoll{
		Linux中的字符设备驱动中有一个函数
		unsigned int (*poll)(struct file * fp, struct poll_table_struct * table){
			此函数在系统调用select内部被使用，作用是把当前的文件指针挂到设备内部定义的等待
		}
		int poll(struct pollfd fds[], nfds_t nfds, int timeout){
			fds：是一个struct pollfd结构类型的数组，用于存放需要检测其状态的Socket描述符；每当调用这个函数之后，系统不会清空这个数组，操作起来比较方便；特别是对于socket连接比较多的情况下，在一定程度上可以提高处理的效率；这一点与select()函数不同，调用select()函数之后，select()函数会清空它所检测的socket描述符集合，导致每次调用select()之前都必须把socket描述符重新加入到待检测的集合中；因此，select()函数适合于只检测一个socket描述符的情况，而poll()函数适合于大量socket描述符的情况；
			nfds：nfds_t类型的参数，用于标记数组fds中的结构体元素的总数量；
			timeout：是poll函数调用阻塞的时间，单位：毫秒；
		}
		struct pollfd {
			int fd; /*文件描述符*/
			short events; /* 等待的需要测试事件 */
			short revents; /* 实际发生了的事件，也就是返回结果 */
		};
	}
	epoll{
		Linux内核为处理大批量文件描述符而作了改进的poll，是Linux下多路复用IO接口select/poll的增强版本
		它无须遍历整个被侦听的描述符集，只要遍历那些被内核IO事件异步唤醒而加入Ready队列的描述符集合就行了
		epoll除了提供select/poll那种IO事件的水平触发（Level Triggered）外，还提供了边缘触发（Edge Triggered）
	}
	->水平触发&边缘触发{
		水平触发:如果文件描述符已经就绪可以非阻塞的执行IO操作了,此时会触发通知.
		允许在任意时刻重复检测IO的状态,没有必要每次描述符就绪后尽可能多的执行IO.
		select,poll就属于水平触发.
		边缘触发:如果文件描述符自上次状态改变后有新的IO活动到来,此时会触发通知.
		在收到一个IO事件通知后要尽可能多的执行IO操作,因为如果在一次通知中没有执行完IO那么就需要等到下一次新的IO活动到来才能获取到就绪的描述符.
		信号驱动式IO就属于边缘触发.
		
		->>
			水平触发:也就是只有高电平(1)或低电平(0)时才触发通知,只要在这两种状态就能得到通知.上面提到的只要有数据可读(描述符就绪)那么水平触发的epoll就立即返回.
			边缘触发:只有电平发生变化(高电平到低电平,或者低电平到高电平)的时候才触发通知.上面提到即使有数据可读,但是没有新的IO活动到来,epoll也不会立即返回.
		comment: 每次只要可读写就读写 ； 除非有新可读写事件，不然即使之前的没结束也不读写。
	}
	EAGAIN

	URI/URL{
		URI 是从虚拟根路径开始的
		URL是整个链接
		如URL http://zhidao.baidu.com/question/68016373.html  
		URI 是/question/68016373.html
		在摆渡那边服务器上把http://zhidao.baidu.com/制作成了虚拟的路径
		的根
	}

	官方Nginx+的文档比较详细，Nginx+和Nginx差异大吗{
		Nginx+在Nginx开源社区版的基础上，增加了企业级的特性，比如：

		全功能的HTTP和TCP负载均衡
		高性能的反向代理
		静态内容和动态内容的缓存和卸载
		自适应流媒体教父音视频内容到任意设备
		对应用敏感的健康检查和高可用性
		提供仪表板或API方式的高级活动监控
		高级监控和管理，提供对开发者友好的工具来管理和实时的变更
		会话持久性
		咨询服务

	}

	X-Forwarded-For{
		
	}

	c++的内存分区{
		五大内存分区 
	在C++中，内存分成5个区，他们分别是堆、栈、自由存储区、全局/静态存储区和常量存储区。 
	栈，就是那些由编译器在需要的时候分配，在不需要的时候自动清楚的变量的存储区。里面的变量通常是局部变量、函数参数等。 
	堆，就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。 
	自由存储区，就是那些由malloc等分配的内存块，他和堆是十分相似的，不过它是用free来结束自己的生命的。 
	全局/静态存储区，全局变量和静态变量被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区。 
	常量存储区，这是一块比较特殊的存储区，他们里面存放的是常量，不允许修改（当然，你要通过非正当手段也可以修改，而且方法很多，在《const的思考》一文中，我给出了6种方法） 

	明确区分堆与栈 
	在bbs上，堆与栈的区分问题，似乎是一个永恒的话题，由此可见，初学者对此往往是混淆不清的，所以我决定拿他第一个开刀。 
	首先，我们举一个例子： 
	void f() { int* p=new int[5]; } 
	这条短短的一句话就包含了堆与栈，看到new，我们首先就应该想到，我们分配了一块堆内存，那么指针p呢？他分配的是一块栈内存，所以这句话的意思就是：在栈内存中存放了一个指向一块堆内存的指针p。在程序会先确定在堆中分配内存的大小，然后调用operatornew分配内存，然后返回这块内存的首地址，放入栈中，他在VC6下的汇编代码如下： 
	00401028 push 14h 
	0040102A call operator new (00401060) 
	0040102F add esp,4 
	00401032 mov dword ptr [ebp-8],eax 
	00401035 mov eax,dword ptr [ebp-8] 
	00401038 mov dword ptr [ebp-4],eax 
	这里，我们为了简单并没有释放内存，那么该怎么去释放呢？是delete p么？澳，错了，应该是delete []p，这是为了告诉编译器：我删除的是一个数组，VC6就会根据相应的Cookie信息去进行释放内存的工作。 
	好了，我们回到我们的主题：堆和栈究竟有什么区别？ 
	主要的区别由以下几点： 
	1、管理方式不同； 
	2、空间大小不同； 
	3、能否产生碎片不同； 
	4、生长方向不同； 
	5、分配方式不同； 
	6、分配效率不同； 
	管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。 
	空间大小：一般来讲在32位系统下，堆内存可以达到4G的空间，从这个角度来看堆内存几乎是没有什么限制的。但是对于栈来讲，一般都是有一定的空间大小的，例如，在VC6下面，默认的栈空间大小是1M（好像是，记不清楚了）。当然，我们可以修改： 
	打开工程，依次操作菜单如下：Project->Setting->Link，在Category 中选中Output，然后在Reserve中设定堆栈的最大值和commit。 
	注意：reserve最小值为4Byte；commit是保留在虚拟内存的页文件里面，它设置的较大会使栈开辟较大的值，可能增加内存的开销和启动时间。 
	碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出，在他弹出之前，在他上面的后进的栈内容已经被弹出，详细的可以参考数据结构，这里我们就不再一一讨论了。 
	生长方向：对于堆来讲，生长方向是向上的，也就是向着内存地址增加的方向；对于栈来讲，它的生长方向是向下的，是向着内存地址减小的方向增长。 
	分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。 
	分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是C/C++函数库提供的，它的机制是很复杂的，例如为了分配一块内存，库函数会按照一定的算法（具体的算法可以参考数据结构/操作系统）在堆内存中搜索可用的足够大小的空间，如果没有足够大小的空间（可能是由于内存碎片太多），就有可能调用系统功能去增加程序数据段的内存空间，这样就有机会分到足够大小的内存，然后进行返回。显然，堆的效率比栈要低得多。 
	从这里我们可以看到，堆和栈相比，由于大量new/delete的使用，容易造成大量的内存碎片；由于没有专门的系统支持，效率很低；由于可能引发用户态和核心态的切换，内存的申请，代价变得更加昂贵。所以栈在程序中是应用最广泛的，就算是函数的调用也利用栈去完成，函数调用过程中的参数，返回地址，EBP和局部变量都采用栈的方式存放。所以，我们推荐大家尽量用栈，而不是用堆。 
	虽然栈有如此众多的好处，但是由于和堆相比不是那么灵活，有时候分配大量的内存空间，还是用堆好一些。 
	无论是堆还是栈，都要防止越界现象的发生（除非你是故意使其越界），因为越界的结果要么是程序崩溃，要么是摧毁程序的堆、栈结构，产生以想不到的结果,就算是在你的程序运行过程中，没有发生上面的问题，你还是要小心，说不定什么时候就崩掉，那时候debug可是相当困难的：） 
	对了，还有一件事，如果有人把堆栈合起来说，那它的意思是栈，可不是堆，呵呵，清楚了？
	}

	程序内存一般的分区{
		对于一个进程的内存空间而言，可以在逻辑上分成3个部份：代码区，静态数据区和动态数据区。动态数据区一般就是“堆栈”。“栈 (stack)”和“堆(heap)”是两种不同的动态数据区，栈是一种线性结构，堆是一种链式结构。进程的每个线程都有私有的“栈”，所以每个线程虽然 代码一样，但本地变量的数据都是互不干扰。一个堆栈可以通过“基地址”和“栈顶”地址来描述。全局变量和静态变量分配在静态数据区，本地变量分配在动态数 据区，即堆栈中。程序通过堆栈的基地址和偏移量来访问本地变量。

		├———————┤低端内存区域 
		│ …… │ 
		├———————┤ 
		│ 动态数据区 │ 
		├———————┤ 
		│ …… │ 
		├———————┤ 
		│ 代码区 │ 
		├———————┤ 
		│ 静态数据区 │ 
		├———————┤ 
		│ …… │ 
		├———————┤高端内存区域
	}

	Cache{
		高速缓冲存储器(Cache Memory)
		内存是以系统总线的时钟频率工作的，这个频率通常也就是CPU的外频(对于雷鸟、毒龙系列的处理器，由于在设计采用了DDR技术，CPU工作的外频为系统总线频率的两倍)。但是，CPU的工作频率(主频)是外频与倍频因子的乘积
		知道一般Cache分为L1 Cache(其中又分为数据Cache、代码Cache)、L2 Cache就行了
	}

	___cdecl{
		__cdecl 是C Declaration的缩写
		表示C语言默认的函数调用方法：所有参数从右到左依次入栈，这些参数由调用者清除，称为手动清栈。被调用函数不会要求调用者传递多少参数，调用者传递过多或者过少的参数，甚至完全不同的参数都不会产生编译阶段的错误。
	}

	ISA{
		Internet Security and Acceleration
		ssl隧道
	}

		
	yum{
		list all
		{rpm -qi/-ql + xxx}
	}
}

*dailycode{
	【code】鉴权里有些工具函数可以保存下来用
	*一致性hash
	*自制进程/线程锁 half
	*浏览器对服务器请求高负载/高并发的模拟
	*base64 en/decode
	*智能分行
	*异步非阻塞事件框架
	*指定大小的文件生成器
	*nginx - upstream 大文件请求，管道模式
	*负载均衡算法{
		http://www.tuicool.com/articles/RJzM7rF
	}
	*内核缓冲区偷窥 http://blog.csdn.net/stpeace/article/details/45009927
	*myHomePage
	*level/edge sample test
	*dailycode:二叉树，二叉树深度/广度优先遍历
	*简单用户注册登录系统
	*http报文分析
	*人类做乘法运算
	*代码高亮
	*遗传算法实现
	打印结构和各种戳 done? -打印各变量开始的地址
	*内存状态绘制工具
	*控制cpu核占用率
	*机器学习玩俄罗斯方块
	*UnitTest框架
	*占用内存探测
	
}
*weeklyblog{
	*整理简单的易错知识，比如返回时的拷贝，和其它隐式拷贝
	*计算机7层网络梳理
	*操作系统知识梳理
	*算法和数据结构知识梳理
	*RPC知识梳理
	*网络服务器知识梳理
	*技术串讲方式
	*时间管理与高并发与进程控制 多线程的极限是慢于单线程状态机的
	*传播知识的方法 读/讲
	学校的精神 - 包容？ 学术？ 静穆？
	
}

*todo{
    Study{
        
        ip命令中的各种意思{
            linux 系统管理 命令教程
            https://www.cyberciti.biz/faq/linux-ip-command-examples-usage-syntax/
            
            ip a del 192.168.85.200/32 dev lo
        }
        
        linux api{
            定义、函数、符号查询
            http://elixir.free-electrons.com/linux/v2.6.32.57/ident/ip_vs_get_vip_groups
            网络配置{
                ioctl()
            }
            
        }
        
        骨干网络拓扑{
            最新骨干网络国际出口带宽（2013.7.17CNNIC发布）
            主要骨干网络国际出口带宽数
            
            国际出口带宽数（Mbps）
            中国电信 1,118,249
            中国联通 677,205
            中国移动 244,594
            中国教育和科研计算机网 35,500
            中国科技网 22,600
            中国国际经济贸易互联网 2
            合计 2,098,150
        }
        
        ES{
            elastic stack
            elk
            elasticsearch(ES)搜索+ logstash数据采集 + kibana前端
            cloud
            
            ES 基于lucene，java实现，提供RESTful API 
            
            基本概念
            doc es基本单位，基于json
            index 类似feature doc set
            type: logic
            filed: 字段
            
            es 类关系型数据库，数据库为索引，表为类型，行为文档，列为域
            
            log stash:
            实时输入、输出、处理数据的数据收集引擎
            jruby
            input(plugin)-filter-output(plugin)
            tags表示匹配是否成功？
            
            beats 系列工具: (golang?)
            file,packet,metric,heart,winlog beat 
            
            filebeat:
            prospectctor
            每个日志启动一个harvester监控，
            spooler收集，然后发送到特定 下游
            
            kibana:
            提供数据分析的前端展示工具
            
            前端使用：
            搜索语法：
            字段搜索 无引号是模糊匹配，否则为精确
            全文搜索，直接搜
            通配符匹配单个字符?, *匹配多个
            范围搜索 code:[a to b] cod:>499
            连接词 AND/OR
            
            VISUALIZE可视化功能
            
            常用场景：
            网站内搜索，数据关键词高亮，粉刺、搜索建议
            大规模日志实时数据分析
            
            concept:
            beats series
            kafka
            Storm集群？
            es 5~6 00 million
            ip识别工具，ip库
            
            Note:
            fields中的百分比不是完全的，只是最近500条
            
            
            Q:
            逻辑连词？ AND OR + - (NOT)
            后台的数据存储方式？
            log stash可以存数据？存在ES里
        }

        lvs, linux网络{
            - lsmod
            - keepalived
            - ipvsadm
            - arp广播
            - 路由原理
            - VRRP
            - ICMP
            - /var/log/messages
            - VIP，网络配置
            {
                - 转发：
                - echo 1 > /proc/sys/net/ipv4/ip_forward
            - Broadcast Address
                - x.x.x.255
                - 直接广播、受限广播 	
                - 传输层只有UDP可以广播
                - 在winsock实现中, 有一个选项对应是否允许广播.
            必须调用setsockopt打开该选项.
                - . 打开后, 用sendto向255.255.255.255发送的数据包全部广播.
                - 合法的广播地址就是主机的网络地址加上最大的主机号。网络地址通过机器的ip地址与子网掩码按位与得出，我们以ip地址为10.78.202.175 ，子网掩码为255.0.0.0
            - DHCP
                - DHCP（Dynamic Host Configuration Protocol，动态主机配置协议）是一个局域网的网络协议，使用UDP协议工作， 主要有两个用途：给内部网络或网络服务供应商自动分配IP地址，给用户或者内部网络管理员作为对所有计算机作中央管理的手段
                - DHCP有3个端口，其中UDP67和UDP68为正常的DHCP服务端口，分别作为DHCP Server和DHCP Client的服务端口；546号端口用于DHCPv6 Client，而不用于DHCPv4，是为DHCP failover服务，这是需要特别开启的服务，DHCP failover是用来做“双机热备”的


            - RESTful API
                - Representational state transfer
                - 把Roy Fielding的博士论文仔细读10遍，其它乱七八糟的书都不用看

            - 关于学习，每种东西学一样开源的，其它的关注特点
            - linux网络配置
                - ifconfig是查看网络配置信息，用ifconfig eth0 ip 是配置eth0的ip地址， route add default gw IP 是添加默认网关，ifdown eth0,是关闭网卡，ifup eth0是激活，也可以在/etc/sysconfig/network-scripts/ifcfg-eth0里面进行配置，刚才那些命令都是临时配置，而在/etc/sysconfig/network-scripts/ifcfg-eth0里面的配置是永久的
                - 感觉要记太杂了，应该弄本手册

                - 主要概念
                    - IP地址
                    - 子网掩码
                    - 网络地址（IP+掩码运算）
                    - 网关（即入口和出口）

            - arp协议
                - 地址解析协议，即ARP（Address Resolution Protocol），是根据IP地址获取物理地址的一个TCP/IP协议
                - 为使广播量最小，ARP维护IP地址到MAC地址映射的缓存以便将来使用。ARP缓存可以包含动态和静态项目。动态项目随时间推移自动添加和删除。每个动态ARP缓存项的潜在生命周期是10分钟。新加到缓存中的项目带有时间戳，如果某个项目添加后2分钟内没有再使用，则此项目过期并从ARP缓存中删除；如果某个项目已在使用，则又收到2分钟的生命周期；如果某个项目始终在使用，则会另外收到2分钟的生命周期，一直到10分钟的最长生命周期。静态项目一直保留在缓存中，直到重新启动计算机为止。
                
                - 地址224.0.0.0~224.0.0.255,用于局域网，路由器不转发属于此范围的IP包，路由器本地链接地址分配如下：
                

                224.0.0.1–在本地子网的所有系统
                
                224.0.0.2–在本地子网的所有路由器
                
                224.0.0.5–OSPF 路由器
                
                224.0.0.6–OSPF 指定路由器
                
                224.0.0.9–RIPv2 路由器
                
                224.0.0.10–IGRP 路由器
                
                224.0.0.13–PIMv2 路由器

            - 关于判断
                - 二分讨论法、多分讨论法、主次讨论法
                - 不确定则存疑，可能答案及置信系数
            - whois

            - yum
                - yum search whois
                - yum whatprovides whois
                - yum whatprovides */bin/whois*

            - NAT内外网转换、转发过程
            -	 NAT设置可以分为静态地址转换、动态地址转换、复用动态地址转换
                - 可以通过接口做转发
                - 注意：当多个用户同时使用一个IP地址，外部网络通过路由器内部利用上层的如TCP或UDP端口号等唯一标识某台计算机。
            - 路由器和机器的连接过程
                - 路由系统OpenWRT
            - 无线网的连接过程

            - ifconfig内容

                - UP BROADCAST RUNNING SLAVE MULTICAST
                    - Linux bonding 主备模式slave网卡切换
                    - http://www.cnblogs.com/dkblog/p/3613407.html
                    - 
                - MTU是Maximum Transmission Unit的缩写，意思是网络上传送的最大数据包，单位是字节。不同的接入方式，MTU值是不一样的，如果值太大就会产生很多数据包碎片，增加丢包率，降低网络速度。我们平常使用的宽带PPPoE连接方式，其MTU值最大为1492

            - keepalived redhat手册
                - https://access.redhat.com/documentation/en-US/Red_Hat_Enterprise_Linux/7/html/Load_Balancer_Administration/ch-initial-setup-VSA.html#s1-initial-setup-conf-VSA

            - tcpdump -i any port 80 and host 192.168.85.1 -nn
            - iptables -L
            - iptables -F
            - echo "1" > /proc/sys/net/ipv4/ip_forwarding 
            - ip r
            - ip a
            - tcpdump -i any -nn
            }
        }
        
        nginx{
            headers more
            more_set_headers 'a: b';
        }
        
        数据库的并发处理问题
        
        DNS知识{
            报文
            BIND(Berkley Inet Name Domain)
        }
        游戏服务器的小数据，但是低延迟的实现{
            低延迟的并发
        }
        
        mp4格式细节{
            box
            帧信息，时间信息，关键帧
            声音、画面、同步
        }
        
        influxdb{
            - database
            - measurement like table in SQL
            - tag indexed; field is not
        }
        
        crontab{
            配置时间，自动运行
            crontab -e编辑
            -l显示
        }
        
        网络异步库{
            libev,libevent, libuv, proxygen, asio
        }
        
        c++11 lambda{
            [ capture ] ( params ) mutable exception attribute -> ret { body } 	(1) 	 
            [ capture ] ( params ) -> ret { body } 	(2) 	 
            [ capture ] ( params ) { body } 	(3) 	 
            [ capture ] { body } (4)
        }
        
        cgroup{
            节点机器上，会混部程序，分为几类：
            1. cache相关：nginx、cache；io密集
            2. 统计相关：kafaka、统计、日志处理等；cpu密集型
            需要为这两类做下CPU核心、内存的隔离
            
            你研究下cgroup原理 及 使用中的管理，不要用docker，lxc这些。系统是centos6，参考下面的
            https://access.redhat.com/documentation/zh-CN/Red_Hat_Enterprise_Linux/6/html/Resource_Management_Guide/index.html
        }
    }
    
    用数据库+页面做一个自己的个人信息管理系统{
        
        - 因为轻量级，考虑sqlite
        - 一般分成纯文本和非纯文本内容（如pdf,word）,短内容，如一句话
        - sqlite 上存索引，具体内容存文件？
    }
    
    
	设计和实现流程{
		UML，DSL
	}
	
	Automake工具/cmake工具
    
    awk/linux cmds {
        http://man.linuxde.net/sed
        http://www.cnblogs.com/ggjucheng/archive/2013/01/13/2858470.html
        
        - awk match($1,~/xxx/,a) print a;， 正则
        - sed -i 's/a/b/' filename
        
        {
            1.awk命令使用双引号的情况下
	
            此时在awk命令里面使用\"$var\"就可以引用外部环境变量的var的值
            
            $ var="BASH";echo "unix script"| awk "gsub(/unix/,\"$var\")"
            
            2.awk命令使用单引号的情况下
            
            此时在awk命令里面使用"'"$var"'"就可以应用外部变量var的值，注意五个点表示两个双引号之间有一个单引号
            
            $ var="BASH";echo "unix script"| awk 'gsub(/unix/, "'"$var"'")'
            BASH script
            
            3.awk的参数-v  (推荐)
            
            这个没什么好解释的，应该是用得比较多的一种方法了，就是使用-v参数，加带一个变量极其赋值
            
            $ echo "unix script"| awk -v var="BASH" 'gsub(/unix/, var)'
            BASH script


              awk向shell变量传递值

            “由awk向shell传递变量”，其思想无非是用awk(sed/perl等也是一样)输出若干条shell命令，然后再用shell去执行这些命令。
            
            eval $(awk 'BEGIN{print "var1='str1';var2='str2'"}')
            
            或者eval $(awk '{printf("var1=%s; var2=%s; var3=%s;",$1,$2,$3)}' abc.txt)
            
            之后可以在当前shell中使用var1,var2等变量了。
            
            echo "var1=$var1 ----- var2=$var2"
        }
    }
	
	【汇编】
	http://blog.csdn.net/striver1205/article/details/25695437
	http://blog.chinaunix.net/uid-16459552-id-3328601.html
	【QA】c++实现细节：
	http://www.oschina.net/question/565065_72355
	【TODO】ATS的热点保留机制、Cache的目录部分，如果不需要删目录，怎么维护？{
		URI和hash的对应关系是定死的，所以hash的值的个数x4就是总目录数，当hash碰撞时会检查
	}
	【TODO】APUE thread/thread control
	【TODO】
	总结准备串讲的方法步骤
	QQ cache ok
	线程模型图
	log相关
	prefetch ok 
	协程contiuation
	COSS的优劣对比{
		squid的建议：小文件使用COSS大文件使用ufs
		ATS中只用COSS系统
	}
	总结近期可公开代码到github上
	虚拟机架个SVN
	其它如：vim
	【QA】CENTOS网络安全的层级 -> linux 网络http://blog.csdn.net/echoisland/article/details/6993756
	【Q】日志定期备份清理
	【Q】ATS 连接server的时候有一个server 连接 pool?
	
	
	【Q】TS内存缓存还不了解详细结构
	COSS的优势【待续】
	首先，如果不是循环buff，那么每次存要找到合适的大小开销应该更大一些？
	第一次接近存满之后，后面如果要存新内容，就要删除旧内容，存储空间容易碎片化，删除旧内容的逻辑也会复杂？，然后可以参考一下内存里面为什么又不用COSS？
	
	read while writer要读代码
	之前笔记中的[?]
	collapsed_forwarding 折叠回源
	
	[!]学习计划{
		Qs{
			笔记中疑问部分
		}
		small{
			进程和线程
			hash、
			协程、异步回调、事件驱动
			内存、
		}
		Perl +　正则
		Python
		ATS配置、架构、代码
		ATS源码
		squid源码
		CDN技术详解
		CDN: NGINX + ATS配置搭建
		further:{
			CDN简易系统
			CDN节点建立
			在IDC建立节点的步骤
			如何建立监控
			高可用性
			性能和压力测试方式
			会不会有安全问题，防攻击
		}
		APUE, 
		gdb使用{
            http://bbs.chinaunix.net/thread-150524-1-1.html
            follow子进程
            (gdb) catch fork
            (gdb) catch vfork
            set follow-fork-mode child
            set detach-on-fork off
            http://blog.csdn.net/pbymw8iwm/article/details/7876797
            breakpoint,awatch,next step        
            http://www.cnblogs.com/TianFang/archive/2013/01/20/2868889.html
            info inferiors
            info threads
            
        }
		coredump处理
		Unix高级网络编程，
		Linux流操作基本
		TCP/IP详解，
		算法导论，
		操作系统，
		Apache,
		适当的数学和量子力学基础
		cosi 的原理
	}
	
	Unix网络编程;APUE;CDN详解
	linux管道操作，如何传输参数，缓存？
	
	串讲的时候可以把整个运行时内存状态，各块数据结构内存，共享内存的状态都图示出来
	！实际模块实例
	！各个东西的实例
	！响应高并发时的实际情况模拟

	errno常量11(EAGAIN)，字面意思error,again 解释:Resource temporarily unavailable
		这表明你在非阻塞模式下调用了阻塞操作，在该操作没有完成就返回这个错误，这个错误不会破坏socket的同步，不用管它，下次循环接着recv就可以。对非阻塞socket而言，EAGAIN不是一种错误。在VxWorks和Windows上，EAGAIN的名字叫做EWOULDBLOCK。

	
	*深入理解nginx
	*Ketama Consistent Hash
	
	*SSL & HTTPS
	*X-Forwarded-For
	
	*nginx 内存池 http://www.ituring.com.cn/article/17520
	
	*user/kernel space & syscall{
		运行状态不同
		运行状态不同。系统调用的调用过程和被调用过程运行在不同的状态，而普通的过程调用一般运行在相同的状态。[2] 
		调用方法不同
		调用方法不同。系统调用必须通过软中断机制首先进入系统核心，然后才能转向相应的命令处理程序。普通过程调用可以直接由调用过程转向被调用过程。[2] 
		返回问题
		返回问题。在采用抢先式调度的系统中，当系统调用返回时，要重新进行调度分析――是否有更高优先级的任务就绪。普通的过程调用直接返回调用过程继续执行。
	}
	
	CGI{
		Common Gateway Interface
	}
	
	*Perl normal expression
	*Nagle Algorithm{
		处理他所谓的小包问题的方法
		在未确认数据发送的时候让发送器把数据送到缓存里。
		:Nagle算法的基本定义是任意时刻，最多只能有一个未被确认的小段。 所谓“小段”，指的是小于MSS尺寸的数据块，所谓“未被确认”，是指一个数据块发送出去后，没有收到对方发送的ACK确认该数据已收到。
		任何数据随后继续直到得到明显的数据确认或者直到攒到了一定数量的数据了再发包。
		这种方法在包括因特网在内的整个网络里得到了推广，成为了默认的执行方式，
		尽管在高互动环境下有些时候是不必要的，例如在客户/服务器情形下
		在这种情况下，nagling可以通过使用TCP_NODELAY 套接字选项关闭。
	}
	*cmd:netstat
	*configure & automake
	
	Tengine by a team from taobao
	http://tengine.taobao.org/documentation.html
	
	*truncked 传输
	
}

knowledge{
    STL{
        下面不对，内存池是在malloc里面
        stl从gcc3.3以后就不用cache了
        stl内存池似乎不会向系统释放自己不用的内存
        
        http://blog.csdn.net/pizi0475/article/details/6301792
    }
}



REF{
	【REF】sqlite 锁 http://www.cnblogs.com/cxjchen/p/3153553.html
	【REF】ATS wiki
	【REF】
	ATS架构简介http://blog.csdn.net/ljy1988123/article/details/50386458
	【REF】chunk encoding 分块传输编码
	http://blog.csdn.net/xifeijian/article/details/42921827
	
	【REF】阿里云的URL鉴权
	https://help.aliyun.com/document_detail/45210.html?spm=5176.doc49567.6.552.U2K62Q
	【REF】m3u8 hls ts
	http://www.cnblogs.com/haibindev/archive/2013/01/30/2880764.html
	http://blog.csdn.net/langeldep/article/details/8603045
	
	【REF】squid 折叠回源 http://blog.chinaunix.net/uid-8474831-id-3830240.html
	
	ngx主主集群
	http://www.2cto.com/os/201109/106387.html
	
	shell 文本流处理
	http://blog.csdn.net/menlinshuangxi/article/details/7979504
	
	nginx if 的rewrite问题
	https://xwsoul.com/posts/761
	
	脚本之家各语言手册
	http://shouce.jb51.net/perl/index.html
	
	服务器 信息
	http://www.server110.com/system/
	
	显卡地址和虚拟内存地址映射
		http://www.cnblogs.com/Wandererzj/archive/2012/04/23/2467127.html
	
	linux kernel{
		栈随机，默认/proc/sys/kernel/randomize_va_space 2
		http://www.2cto.com/os/201212/178306.html
		官方，64位，内存
		https://www.kernel.org/doc/Documentation/x86/x86_64/mm.txt 
		2.6.32
		http://www.cnblogs.com/azenk/p/4674158.html
	}
	
	磁盘
	http://blog.chinaunix.net/uid-23069658-id-3413957.html
	
	python js Node.js 入门
	http://www.liaoxuefeng.com
	
	good blogs{
		【blog】同行
		http://blog.chinaunix.net/uid/13746440/cid-211758-list-5.html
		【blog】ATS 官方交流
		https://blog.zymlinux.net/index.php/archives/756
		【blog】同行，文章是linux启动过程 http://blog.csdn.net/u010954257/article/details/54178144
		ATS使用
		http://blog.csdn.net/u010954257/article/details/54178145
		淘宝，TS、squid
		http://blog.chinaunix.net/uid-23242010-id-2973123.html
		CDN相关信息
		http://www.dnsdizhi.com/
		网络，c,php,基础原理和趣味
		http://blog.csdn.net/21aspnet/article/details/6575705
		算法，量多
		http://blog.csdn.net/stpeace/article/details/38827671
		web/移动端
		http://blog.csdn.net/mergerly/article/details/44306403
		雪峰博客主题
		http://blog.csdn.net/tao_627/article/details/44678225
		磁盘的描述很棒
		http://blog.chinaunix.net/uid-23069658-id-3413957.html
	}
	
	hash
	http://kb.cnblogs.com/page/189480/
	
	协程{
		概念
		http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/0013868328689835ecd883d910145dfa8227b539725e5ed000
		-问题：一次处理一个 还是一整批处理一小部分
		http://blog.csdn.net/qq910894904/article/details/41699541
		
		协程和异步 -Tim Shen的答案
		https://www.zhihu.com/question/32218874
		协程，并发测试相关，注意评论
		http://gashero.iteye.com/blog/442177
	}
	

	C++ IDE http://www.cnblogs.com/findumars/p/5797486.html
	eclipse http://blog.csdn.net/dugujiujian1124/article/details/46801823
	
	shell 文件操作
	http://blog.chinaunix.net/uid-16728139-id-3415706.html
	
	Perl basics:
	http://blog.csdn.net/gexiaobaohelloworld/article/details/8931833
	Perl 正则
	http://www.chinaunix.net/old_jh/25/159388.html
	nginx location 正则
	http://blog.sina.com.cn/s/blog_97688f8e0100zws5.html
	
	TCP backlog 和accept问题http://blog.csdn.net/russell_tao/article/details/9111769
	
	g++ 4.8 http://www.linuxidc.com/Linux/2015-01/112595.htm
	
	静态代码检测工具{
		http://blog.csdn.net/jinhill/article/details/6673734
	}
	
	压力测试工具{
		
		ab,教程
		http://www.cnblogs.com/0201zcr/p/5045730.html
		
		列表1
		http://www.oschina.net/news/30374/10-free-tools-to-loadstress-test-your-web?from=rss
	}
	
	ATS{
		ATS主要内容：
		配置、插件、硬盘cache(类COSS)，memcache(两种算法CLFUS和LFRU?)，进线程(两层进程监控，n+m+ 线程分别对应网络事件处理,硬盘IO,accept，日志)
		，网络IO处理，硬盘IO处理
		
		资料分类{
			集群模拟和监控方法，主要是为了模拟环境，能够运行，不考虑性能{
				docker??
				kvm
				xen?
				microwulf?无盘linux?
				vmware Team?
			}
			压力测试 测试标准，主要考虑性能，不管集群{}
			
			CDN原理，已有的CDN架构分析，CDN部署
			注入？
			4、7层均衡原理
			nginx
			DNS原理 http://www.txrjy.com/forum.php?mod=viewthread&tid=916367
			高并发处理
			HTTP协议
			ATS源码分析{
				https://github.com/oknet/atsinternals
				进线程原理、网络IO模型
				高可用和高并发的保证方式
			}
			ATS框架
			ATS插件，和插件开发
			ATS运维，测试，监控 工具
			http://blog.csdn.net/tao_627/article/details/32718875
			web cache原理
			IO速度方面{
				分为内存/硬盘
				内存结构，提高hit率算法
				磁盘IO，提速原理
				SSD
				RAID
			}
		}
		
		入门建议{
			 【个人心得】

			0、ats目前文档资料是很少，基本搜索不到问题的解决方法，只能在已有的资料上多下工夫

			1、多看官方文档

			2、多看配置文件本身的说明

			3、多做实验测试

			4、首先要把ats的安装目录、配置文件目录、日志目录、插件目录、缓存目录等相关目录弄清楚

			5、会使用基本的辅助工具

			6、了解正则表达式

			7、了解http相关知识，特别是跟缓存控制相关的内容

			8、勤做笔记，像群里经常会讨论一些比较有价值的内容，先记下来方便以后查阅

			9、不要什么都问，像辅助工具、正则等内容自己搜索下资料都能解决的

			【工具】

			1、firebug等基本分析工具的使用

			2、curl查看相应头部
		}
		
		ATS源码分析
		https://github.com/oknet/atsinternals
		
		qq群里的资源
		
		体系{
			雪峰博客主题
			http://blog.csdn.net/tao_627/article/details/44678225
		}
		
		进、线程模型{
			进程+总体
			http://www.cnblogs.com/liushaodong/archive/2013/02/26/2933280.html
			线程的事件处理
			http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=13776576&id=5606097
		}
		
		
		整体，架构，里面说ngx和ats都用了协程？？
		http://blog.csdn.net/ljy1988123/article/details/50386458
		
		使用向，不靠谱
		http://blog.linuxphp.org/archives/1641/
		
		many infos
		https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=2&tn=baiduhome_pg&wd=goaccess%20trafficserver&rsv_spt=1&oq=goaccess%2520ats&rsv_pq=aea4ab0800006a46&rsv_t=e6d0opyeSJEfrLSK0N0tmgptpQtH0YfcIqEmzFCxz5CV22oY%2FD6cd1m2JREjQvl7vXQV&rqlang=cn&rsv_enter=1&sug=goaccess&inputT=5384&rsv_sug3=29&rsv_sug1=14&rsv_sug7=100&rsv_sug2=0&rsv_sug4=6030
		
		浏览器缓存原理：http://www.cnblogs.com/wangpenghui522/p/5498427.html
		
		缓存知识http://www.zhangxinxu.com/wordpress/2013/05/caching-tutorial-for-web-authors-and-webmasters/
		
		2016.1.25 deep look into ATS
		https://www.bizety.com/2016/01/25/deep-look-into-apache-traffic-server/
		
		2016 ATS& CDN
		http://www.infoq.com/cn/presentations/apache-traffic-server-and-cdn-practice
		
		结构简略介绍2016-2
		http://www.open-open.com/lib/view/open1455771560339.html
		
		2010年时的应用情况介绍:http://blog.sina.com.cn/s/blog_502c8cc40100mw7n.html
		
		资料1: https://sanwen8.cn/p/1b5GQep.html
		
		OFFICIAL
		https://docs.trafficserver.apache.org/en/latest/index.html
	}
	
	HTTP1.0/1.1差异
	http://blog.csdn.net/shaobingj126/article/details/51392587
	
	RFC2616
	https://tools.ietf.org/html/rfc2616
	
	开源：gitbug,sourceforge,开源中国
	
	automake http://blog.csdn.net/liang890319/article/details/8274917
	
	传输层和应用层负载均衡 http://blog.jobbole.com/74131/
	
	
	
	云计算/网路安全/软件定义 epoll/select/poll
	*http://www.cnblogs.com/Anker/p/3265058.html
	ngx{
		【REF】ngx types
		http://nginx.org/en/docs/http/ngx_http_core_module.html#types
	
		【REF】ngx rewrite
		http://blog.csdn.net/xiao_jun_0820/article/details/9397011
		
		32位上8字节对齐的原因：保证它分配的地址可以被你cast成任何类型的指针来访问，因此malloc应该不会造成align问题的
		memalign valloc  http://blog.csdn.net/syc0616/article/details/3734941
		
		ngx slab pool: http://www.cnblogs.com/doop-ymc/p/3412572.html
		ngx 内存池分析 http://www.cnblogs.com/doop-ymc/p/3418514.html
		
		nginx事件/内存
		http://www.cnblogs.com/fll369/archive/2012/11/29/2794939.html
			
		Nginx教程：Nginx 变量漫谈；配置指令执行顺序(细节)
		*https://openresty.org/download/agentzh-nginx-tutorials-zhcn.html 

		*nginx API and developers' documentation
		*http://blog.csdn.net/lxzo123/article/details/6707054 深入理解HTTP协议（转） 
		
		*Andrew :Chapter “nginx” in “The Architecture of Open Source Applications”
		*The Architecture of Open Source Applications http://www.aosabook.org/en/index.html
		*NGINX ADMIN DOC https://www.nginx.com/resources/admin-guide/?_ga=1.52767648.966571952.1482822187
		Nginx开发从入门到精通完整 *http://tengine.taobao.org/book/chapter_05.html  
		nginx源码分析 2011 *http://blog.csdn.net/livelylittlefish/article/category/838107  
		nginx源码学习资源 2012 *http://www.cnblogs.com/yjf512/archive/2012/06/13/2548515.html 
		
		module config *http://blog.csdn.net/poechant/article/details/7657955 
	}
}

easymistake{
	linux防火墙 http://www.myhack58.com/Article/48/66/2014/51687.htm
	need module points, should pass as address
}

shellcmd{
	tail awk
}

mail{
	sys@isurecloud.com zhaoziyi@isurecloud.com     xiaoguang@isurecloud.com
	{
		学习内容：{
			安装NGINX，修改配置文件，运行简单的HTTP服务器，和简单的proxy服务器
			对NGINX基本的信号操作
			
			NGINX的模型特点，
			网络事件处理方式，
			select/poll/epoll区别
			了解了一些概念：水平触发，边缘触发；Nagle算法；反向代理；
			
			学习NGINX Admin Guide and Tutorial文档中配置方法
			Basic Functionality部分{
				*Web server
				*Serving static content
			}
		}
		
		遇到问题：{
			Nginx的config文件写法里，用到Perl的正则表达式不太熟悉。
			X-Forwarded-For？
			geo 指令里，有一句
			geo $country {
				...
				proxy          2001:0db8::/32; #不理解意思 IPV6？为什么只有64位？和XFF有关吗？
			}
			
		}
		明天计划：{
			Nginx处理请求的基本过程
			
			学习NGINX Admin Guide and Tutorial文档
			Basic Functionality 部分{
				Reverse proxy 
				Compression and decompression
				Web content cache
			}
			Load Balancing 部分{
				HTTP load balancer
				TCP and UDP load balancer
				Using the PROXY protocol
			}
			
			
		}
	}
}

thoughts{
    自己做一个多线程断点续传下载工具
    
    用多个关键字可搜索的笔记系统{
        比如可以搜方法论
        可以搜linux 命令
        可以搜网络
        等等等等
    }
    
    接upwork可以考虑团队，可以找的人{
        - 稳定的有：希强、欢哥、建明
        - 不稳定的：砚龙、俐榕、能哥、晓清
    }
    
    抓肉鸡，做分布式工作集群
    
    python dict的实现
    
    测试自动化：文本修改自动化
    
    - how to become freelancer see知乎
    - X windows server

    - vim script
    - JS, DOM and webdev see知乎
    ginx conf高亮文本编辑器
    print x bit HEX ： to git
    可以直接拖图标的开机助手
    
    asyncio, 异步库asynclib?
	【】push和pop线程安全的list
	[website]各种可靠的数据记录 名称，日期，出处，可信度
	[tool] 程序各阶段耗时检测工具
	【code】工作进度记录器
	【TOOL】boost lib
	【关于并发和延迟】游戏服务器的通信实现
	【关于协程coroutine】和普通函数调用的区别是，子函数会在阻塞时返回，并保有环境
	【shellcode】http://www.zixijiaoshi.com/html/server/Linux/2014/1225/13844.html
	http://blog.csdn.net/mikayong/article/details/52057818
	【thought】libeventcode
	【thought】
	编写状态机
	【thought】grafana做自定义的数据可视化
	【Q】websocket 全双工通信 好像很适合用于页游和网页即时聊天
	原理
	http://www.cnblogs.com/purpleraintear/p/6158104.html
	
	【thought】
	GO R lang
	【thought】:工作空间自动打开，并做成网页按钮，用于个人主页
	【thought】复合压缩
	
	做一个能生成cookie的服务器来测试
	git上，提交ATS的说明问题
	
	git学习如何向公开项目贡献
	
	感觉自己特别喜欢模拟： 模拟-建模-解决问题
	如何做本我问题-长期压抑，渴望创造；
	社会我保证基本的自制和生存。
	修通阻碍，自由探索：
	1.社会我应当为本我服务，整合两者。
	2.了解自己解析自己，探索世界
	
	读paper?
	
	搭建一个jenkins编译服务器
	tc写一些模拟特定情况的通信双方的脚本
	
	一次网页访问流向图，客户端如游戏时流向
	自制搜索引擎？！怎么样获取所有可用域名或IP呢？
	开源浏览器？
	
	网络环境概况图 服务商，用户，黑客，中间商，私网，公网
	
	画简易图笔记
	
	自顶向下设计
	
	计算速度缩放，用于并发实验
	
	电路级计算机 - 电子级(量子级) - 幂的底数不同2~n计算能力剧变
	
	分享系统学习体系的学习网站
	
	回拨方式解决端口耗尽问题？
	可以用rewrite防爬模块来作为http handler的例子
	method:阅读方法：{阅读速度理解速度，同理学习方法；}
	动作+物体 简单语法 实现小助手{
		动作+物体
		"定义"+概念+解释
		其它？
		概念+形容词准确定义: 取 20个 不同的 XXX 网站
	}
	
	lz4可能是目前最快的内存压缩算法？；xmemcpy&memcpy&strcpy
	数据集可视化工具
	百度云产品
	https://cloud.baidu.com/product/bml.html
	开源浏览器
	维护简历和linkedin
	math & physics & opensource work
}

书{
	《深入Linux内核架构》
}

总结{
	【总结】：在总结的时候有内容的罗列，问题或者QA，资料，系统的联系导图，及想法。在罗列的时候过一块内容也要小结一下
}

tool{
	【tool】
	流程图工具 edraw
	http://www.360doc.com/content/13/1024/22/9200790_323876899.shtml
	https://www.processon.com/
	Xmind思维导图工具
}

standard{
	[?]用来标记代码中不明白的地方[!]标记重要的地方
}