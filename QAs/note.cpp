immediatenotes{
	��Ҫ��ʱת����ĵط����ֶ�С��
	-----------------------
	����ǰ�����Ҫ��ʲô˵���
	
	�¹������˻�{
		���֤�����п�
	}

	
	������¼�������̣�����Ҫ����������������
	�ܽ�һ�½������Ĺ��������ȶȣ�����Ǳ�ڹ�����
	
	���֪ʶ�����ķ��࣬�����
	
}
daily{
	dailycheck 3/21
	ÿ�����Ͽ���ǰ��һ��potato���ƻ�������ʱ��һ�����ܽᣬ�ܽ��Ǵ������note�ĸ���	0/21
	���ϻؼҺ���Ҫ�ȼ������Ҫ���Ķ���	0/21
	exercise{
		even /oddoreven
		chest 50/100
		abdomen 25/100
		leg front 0/100
		*leg back 50/100
	}
	
}

daily notes{
	�������ƻ�{
		config�Ĺ�������Լ2h*10*2 = 40h,����ʱ����Ҳ��40h,���ǽ����Ķ�Ҫ�㶨
	}
	ATS����
	�¼���˼ά��ͼ
}

ATS todo{
	
	ǰ�����������
	��칤�߲����ã�
	����
	���
	��Žṹ
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
	��setup env��openresty + luarocks +��������
	
	��REF����nginx��openresty�Ĵ�������
	
	location ��ϸ
	http://blog.csdn.net/xy2204/article/details/47749405
	
	rewrite ����ѡ��
	http://www.76ku.cc:90/articles/archives/317
	
	����ģ�⣺
	��̬��
	�����ö�˿ڣ�����L1��nginxǰ�ˣ�ǰ��upstram�����L2��TS���棬TS����L3��nginxԴ��������
	L3�ķ�����Դ�ļ����ڸ���
	�������ܵĲ㼶������̫�࣬����Ӧ��һ��һ���
	ѹ������������ٶȣ�������
	
	��־����{
		GoAccess
	}
	
	ƽ������http://zachary-guo.iteye.com/blog/1358312
	
	curlҪ����������
	upstream 1.10Ĭ�϶�������Ҫproxy_http_version 1.1;
	��Ҫkeepalive 16;16Ϊһ��worker���������ĸ���;?
	
	�Ż������ο�
	
	start progress{		
		ʱ�䡢���򡢴�����־��ssl�ȳ�ʼ��
		���������в���
		OS��س�ʼ��
		���벢��������
		����ģ���ʼ��
		����������ʱ�ļ���Ŀ¼
		���������ڴ�
		��listen�Ķ˿�
		����ģ���ʼ��
		����worker����

	}
	
	important notes{
		ngx_str_t not end with '\0';
		���������ڵ���ϵͳapiʱ���Ͳ���ֱ�Ӵ���str->data�ˡ�
		��ʱ��ͨ���������Ǵ���һ��str->len + 1��С���ڴ棬Ȼ��copy�ַ��������һ���ֽ���Ϊ��\0����
		
	}
	
	Basic Functionality
	{
    Web server �C Configuring virtual servers and locations, using variables, rewriting URIs, and customizing error pages
    Serving static content �C Setting the root directory for requested content, and creating ordered lists of files to serve if the original index file or URI does not exist
    Reverse proxy �C Proxying requests to HTTP, FastCGI, uwsgi, SCGI, and memcached servers; controlling proxied request headers; and buffering of responses from proxied servers
    Compression and decompression �C Compressing responses on the fly to minimize use of network bandwidth
    Web content cache �C Caching static and dynamic content from proxied servers
	}
	ģ���ص�
	{
		master worker
		�첽���������������л���������Դ�˷�
		�Ż�������Ҫ��CPU�ˣ��ַ�������ϲ������ͱȽϵȡ�
		
		����һ��������web ��������˵���¼�ͨ�����������ͣ�
		�����¼�(IO)���źš���ʱ����
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
		�������Reverse Proxy����ʽ��ָ�Դ��������������internet�ϵ���������
		Ȼ������ת�����ڲ������ϵķ������������ӷ������ϵõ��Ľ�����ظ�internet���������ӵĿͻ��ˣ�
		��ʱ�������������ͱ���Ϊһ����������������
		�����������Ϊ��˵Ķ�̨�������ṩ����ƽ�⣬��Ϊ��˽����ķ������ṩ�������
		relation with CDN{
			ͨ��������������÷������ڵ�����������ɵ������еĻ���������֮�ϵ�һ�������������磬CDNϵͳ�ܹ�ʵʱ�ظ������������͸��ڵ�����ӡ�����״���Լ����û��ľ������Ӧʱ����ۺ���Ϣ���û����������µ������û�����ķ���ڵ��ϡ���Ŀ����ʹ�û��ɾͽ�ȡ���������ݣ���� Internet����ӵ����״��������û�������վ����Ӧ�ٶȡ�
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
				last �C Stops execution of the rewrite directives in the current server or location context, but NGINX Plus searches for locations that match the rewritten URI, and any rewrite directives in the new location are applied (meaning the URI can be changed again).
				break �C Like the break directive, stops processing of rewrite directives in the current context and cancels the search for locations that match the new URI. The rewrite directives in the new location are not executed.

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
				
			
			tcp_nodelay       on;//By default, the tcp_nodelay directive is set to on which means that the Nagle��s algorithm is disabled. The option is used only for keepalive connections:
			keepalive_timeout 65;
			
			Optimizing the Backlog Queue{
			incoming connections in high load situation
			Measuring the Listen Queue��netstat -tnlp
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

��������ʽ{
		���{
			���������
			�ܹ�
			��ʵ��
		}
		���̶���Ӧ����{
			�ܹ����������á���չ������
		}
		�ڲ�ʹ����{
			api
			������������
		}
		������{
			ҵ���߼�->���� +
			��Ӧ������ݽṹ+api
			���Ӧ��������㷨
			+ʵ�ʴ���ʵ�ּ���
		}
	Խ����Խϸ��
	
}

//note date
QA{
    ����״��{
        http://www.17ce.com
    }
    
    mmap{
        mmap()ϵͳ����ʹ�ý���֮��ͨ��ӳ��ͬһ����ͨ�ļ�ʵ�ֹ����ڴ档��ͨ�ļ���ӳ�䵽���̵�ַ�ռ�󣬽��̿����������ͨ�ڴ�һ�����ļ����з��ʣ������ٵ���read()��write�����Ȳ�����
����ע��ʵ���ϣ�mmap()ϵͳ���ò�������ȫΪ�����ڹ����ڴ����Ƶġ��������ṩ�˲�ͬ��һ�����ͨ�ļ��ķ��ʷ�ʽ�����̿������д�ڴ�һ������ͨ�ļ��Ĳ�������Posix��System V�Ĺ����ڴ�IPC�򴿴����ڹ���Ŀ�ģ���Ȼmmap()ʵ�ֹ����ڴ�Ҳ������ҪӦ��֮һ�� 
    }
    
    ������ʶ����Ӳ��{
        #echo "scsi add-single-device a b c d" > /porc/scsi/scsi

        a��Ӳ������SCSI�������ţ��ҵ�VM��2��SCSI�����������Ծ���1����
        b��Ӳ������SCSIͨ���ı�ţ�һ�㵥ͨ���ľ���0����ͨ����Ҫ�����ĸ�ͨ���ˣ���
        c��Ӳ�̵�SCSI ID�ţ�����ͨ����������Ӳ�̲�����жϣ���
        d��Ӳ�̵�lun�ţ�Ĭ���������0��

        2�������Ӳ��

        [root@lab6-5 ~]# echo "scsi add-single-device 2 0 1 0" > /proc/scsi/scsi
    }
    
    ssh ����{
        sudo ssh -i Ohio-1.pem -Ng -L 32760:127.0.0.1:8080 ec2-user@52.15.125.241
        https://www.zifangsky.cn/916.html
    }
    network tool{
        tracert  (trace route)
    }
    
    git{
        ���������ֿ���ύ����
        git clone --bare
        git push --mirror
        
        rebase �ϲ�ʱ���ѱ���֧�������ύ�ϲ�һ����¼���ύ��origin��
        git rebase origin
        git rebase --continue
        git rebase --abort
    }
    
    ����״̬ �ڴ����{

        PID�����̵�ID
        USER������������
        PR�����̵����ȼ���ԽСԽ���ȱ�ִ��
        NInice��ֵ
        VIRT������ռ�õ������ڴ�
        RES������ռ�õ������ڴ�
        SHR������ʹ�õĹ����ڴ�
        S�����̵�״̬��S��ʾ���ߣ�R��ʾ�������У�Z��ʾ����״̬��N��ʾ�ý�������ֵΪ����
        %CPU������ռ��CPU��ʹ����
        %MEM������ʹ�õ������ڴ�����ڴ�İٷֱ�
        TIME+���ý���������ռ�õ��ܵ�CPUʱ�䣬��ռ��CPUʹ��ʱ����ۼ�ֵ��
        COMMAND������������������

        1��ʹ�� ps -ef|grep xxx ���������Ҫ�鿴�Ľ��̣�xxx�ǽ�������

        2��top -p pid �鿴�������� 

        3��ps -aux | grep process_name

        4��cat /proc/pid/status 
        ������ӡ����ǰ������ϸ����������У��ڴ��� VmRSS�� 
        ע��pid��Ҫ�滻��һ��id���ֵġ�

    }
    
     tc{
         tc qdisc add dev eth0 root netem delay 100ms
     }
    
	malloc() : smallbin double linked list corrupted 
	{
		����Ӧ�ó��������֮ǰ�ĵط����ƻ��˶��ڴ档
		���鵽��double free�����⡣
		Ҫע��free֮��ָ��δ��ΪNULL
	}
	
	GLIBCXX_ not found ����
	{
		 strings /usr/lib64/libstdc++.so.6|grep GLIBCXX ���鿴
		 ��gcc����ʱ��Ŀ¼�����ҵ��ļ���libstdc++.so.6.0.18,�滻
	}
	
	
	���ĵ�д����
	http://www.cnblogs.com/trendline/articles/how-to-create-design-doc.html
	
	kernel panic:initramfs problem
	https://communities.vmware.com/thread/456893
	
	chkconfig
	����������
	
	iptable -2{
		����3306�˿ڲ�����

		/sbin/iptables -I INPUT -p tcp --dport 3306 -j ACCEPT

		/etc/rc.d/init.d/iptables save

	}
	
	gcc includeĿ¼
	`g++ -print-prog-name=cc1plus` -v
	
	�̲߳鿴{
		1��top -H
		�ֲ���˵��-H : Threads toggle
		�������ѡ������top��topһ����ʾһ���̡߳�������һ����ʾһ�����̡�
		2��ps xH
		�ֲ���˵��H Show threads as if they were processes
		�������Բ鿴���д��ڵ��̡߳�
		3��ps -mp <PID>
		�ֲ���˵��m Show threads after processes
		�������Բ鿴һ����������߳�����
		�����꾡�Ľ��ͻ�����man ps��man top��
	}
	��Q��wget
		wget��һ�����������Զ������ļ������ɹ��ߣ�֧��ͨ��HTTP��HTTPS��FTP���������TCP/IPЭ�����أ�������ʹ��HTTP����wget���Ƶ������ǡ�World Wide Web���롰get���Ľ�ϡ�
	��Q��nginx�����ļ��������������������
	��Q��Traffic Control�ᵼ��tcpdump�Ľ���������
	��Q�������ĳ�������Щ���������Ļ���Ŀ�ĺ�ԭ��
	URL��Ȩ������
	nginx_lua{
		ngx_lua�ṩ����Nginx�����ĺܶ��API�����ڿ�����Ա��˵ֻ��Ҫѧϰ��ЩAPI�Ϳ��Խ��й��ܿ�����
		�����ڿ���webӦ����˵������Ӵ���Servlet�Ļ����俪����Servlet���ƣ����������֪���������󡢲������������ܴ���������Ӧ�⼸����API��ʲô���ӵġ�
		
		���ǿ���ʹ��OpenResty�������������OpenResty��Nginx���ġ�LuaJIT��������õ�Lua���Nginx������ģ������һ��
	}
		luaBasic.lua�﷨˵��
	��QA���հ���LUA:��һ�������ڲ�Ƕ����һ����������ʱ���ڲ��ĺ�������Է����ⲿ�ĺ����ľֲ�����������������lua�����ǳ����ʷ����硣
		ʹ�ó�����setmetatable��
		
	��QA��lua���ص㣬Ϊʲôʹ����{
		Lua ���ĺô�����С�����Ե�С������Ƕ���κγ�������Ǽ������Ժ���Ϊ�����ӵĴ�С���������ԵĹ��ܻ������걸�ġ�
		��û�д��� UTF-8 ���߼������е��ַ��������ֽ�������
		
		Lua��������Ƕ��ʽ��
		��ô��;����ճ��ճ��ճ�ϡ�
		����ܺõ���C/C++����Ч���ǳ�����
	}
	
	��Q��cloudflare company
	
	��QA��redis,Twemproxy,  Memcached
	redis��Ϊkey-value���棬�����ṩ�˷ḻ�����ݽ����set��list��map�ȣ�����ʵ�ֺܶิ�ӵĹ��ܣ�����Redis������Ҫ�����ڴ滺��
	Twemproxy
	��һ��Redis/Memcached�����м��������ʵ�������Ƭ�߼���HashTag�������������ȹ��ܣ�
	�������д���Ӧ�÷������ĳ�����Twemproxy�Ľ�ɫ��͹���ˣ�����Ч������������
	
	��QA��Ĭ�϶�̬���ַ/etc/ld.so.conf
	
	straceʹ�ã�
	time/strace׷������ʱ��
	
	open��unlink�Ŀ����� ����д�����ʱ��
	unlink��ʲô�� ������������һ������û������ʹ�õĽ��̣���ɾ����
	
	GO Nginx�ڴ���߲��������Ϸǳ���ɫ����go��Ϊ��ʱ�����������ԣ������֮����Ϊʵ�ָ߲�����ngx_lua��Nginx�����������¼�����ʹ��Э����ʵ�ַ��������Ӷ�ʵ�ָ߲����� go���Լ����ṩ��������api��ͬ��ʹ��Э�����ṩ�߲�������
	
	����ϵͳ{
		���ӽ���ͨ��ӳ�乲�����Ρ�
		��̬�⣺����ӳ��������ݲ�����
	}
	
	cosi ��ԭ��
	
	iptable{
		vi /etc/sysconfig/iptables 
		�� +����� iptables -I INPUT -p tcp --dport 8000 -j ACCEPT
		/sbin/iptables -L -n
		service iptables restart
		http://www.centoscn.com/CentOS/config/2015/0915/6172.html
		http://www.jb51.net/os/RedHat/68744.html
		http://www.linuxidc.com/Linux/2013-07/87045p2.htm
	]
	
	functional Modules: transform conten ok	
	modules: phase handlers ok
	nginx����ʹ�ú����¼�����ģ�飬�������ھ���Ĳ���ϵͳ�ͱ���ѡ�???
	
	�ڶ�upstream��load balance��ʱ����ʱ��Ҫworker֮�乲��һ��zone���ǲ��ǻ��������ͬ�����⣿��Ӱ���ٶȣ�
	http2.0
	
	
	nginx �ڴ����Ӧ����ôȷ����ʲôapi���ʣ�
	Ketama Consistent Hash
	
	*���⻯���������ƣ�Ӳ�������� - ���ƵĹ�ϵ��
	*Э�̣���
	127.0.0.1�ػ�
	ɢ�б� -hash
	*��̬���������
	*volatile
	*��λص����⣬�罨������ʱ - ���� ����Ϊ�ǵ��̴߳�������
	serverѡȡ���ܵ�ͷӰ����
	*nginx�ɼ���ѧϰ����̬ҳ�桢�б������Ĵ���
	�����ض�������ӣ�
	ҳ�η�������ʵ�֣�
	
	*�򵥷���
	
	*�ƶ�������Ҫ����
	
	�鿴�������Ķ˿ںţ�netstat -tnap
	
	�Զ���װ��������һ��λ�ã�./contrib/download_prerequisites��
	
	��Ⱥ�����backlog{
		��� ������ÿ����Դ���ã����еĽ���/�̶߳���������Դ����ɵĺ����
		1��ϵͳ���û�����/�߳�Ƶ��������Ч�ĵ��ȡ��������л���ϵͳϵ�ܴ���ۿۡ�
		2��Ϊ��ȷ��ֻ��һ���̵߳õ���Դ���û��������Դ�������м�����������һ���Ӵ���ϵͳ������
		accept - ���߳�����ʱ�ں���ֻ�ỽ��1��
		
		SYN���Ļظ��ǵײ��Զ���ɵģ���SYN���к�ACCEPT���У��������ǰ��SYN���У���ɺ���ACCEPT����
		tcp��backlog = SYN + ACCEPT
		��ʱ�����糬ʱ��������
	}
	
	TCP�������ӣ�TCB: Transmission Control Block ��Ψһʶ��һ��TCP���ӣ�����Ԫ����ʶ��һ��TCP����̫�����㡣
	{
		���TCP�������û����̵���socket��ʱ�򣬽�����һ��ӳ���ϵ����Ԫ�� <---->session ID (TCB):


[IP Source Address + IP Destination + Source Port +Destination Port+Protocol ] <--->session ID (TCB)

���ߣ���С��
���ӣ�https://www.zhihu.com/question/31079440/answer/106497081
��Դ��֪��
����Ȩ���������У�ת������ϵ���߻����Ȩ��
	}
	
	TCP�����ϵ�����{
		�Ͽ��Ĵ����ֵ�ԭ��
		������д�رպͱ����Ķ��رգ�
		����������𷽹ر�ǰ����һ��MSL��ʱ��
	}
	
	HTTP{
		
		�١����󷽷� URI Э��/�汾
		�ڡ�����ͷ(Request Header)
		�ۡ���������
		������һ��HTTP��������ӣ�

		GET/sample.Jsp HTTP/1.1
		Accept:image/gif.image/jpeg,*/*    ;�����ʽ */
		Accept-Language:zh-cn
		Connection:Keep-Alive
		Host:localhost
		User-Agent:Mozila/4.0(compatible;MSIE5.01;Window NT5.0)
		Accept-Encoding:gzip,deflate
		
		username=jinqiao&password=1234
		
		pipeline{
			http 1.1�涨�������˱��밴��ͬ��˳�򷵻���Ӧ
		}
		
		keep-alive{
			firefoxΪ������TCP����ʵ�֣�Ĭ��10��һ��̽�⣬Ĭ�ϱ���60�룬Ȼ��4�����ֶϿ�
			1.1Ĭ�Ͽ���
			�ŵ㣺����������Ŀ���������pipeline��ʽ����������������ʱ�����ˡ����������Ա��������ֱ�ӶϿ����ӣ�������Http���
			���⣺������EOF���ж�����/��Ӧ����������ô�жϣ�������ʹ��ͷ����Conent-Length(��̬����ʾʵ�峤�ȣ�������ʵ�ʴ��䳤�ȣ��б���ʱ���߲�ͬ)��
			"Transfer-Encoding: chunked"��(��̬��һ�ߴ���һ�߷���)
		}
		HTTP1.1֧��7�����󷽷� GET��POST��HEAD��OPTIONS��PUT��DELETE��TARCE����InternetӦ���У���õķ�����GET��POST
		����ͷ����������֮����һ������
		GET����{
			Ĭ�ϣ�����Ϊurlһ���֣��򵥱���
		}
		POST{
			����Ҫ����Web�������ύ�����ݣ������Ǵ����������ݡ�
		}
		�ӱ�̵ĽǶ�����������û�ͨ��GET�����ύ���ݣ������ݴ����QUERY��STRING���������У�
		��POST�����ύ����������Դӱ�׼�������л�ȡ
	}
	
	TCP��������{
		TCPĬ���Դ�����������ʱ�䳤
		TCP keep-alive / ACK
		TCP_KEEPCNT ����  tcp_keepalive_probes��Ĭ��9���Σ�
		TCP_KEEPIDLE ���� tcp_keepalive_time��Ĭ��7200���룩
		TCP_KEEPINTVL ���� tcp_keepalive_intvl��Ĭ��75����
	}
	
	CNAME{
		DNS��IP��¼���ͣ�
		A��¼��վ�� MX�ʼ�·�ɼ�¼
		TTL����ʱ��
		CNAME������¼�����������ֽ���
	}
	
	CDN��������{
		L4/7������ http://dannyswallow.blog.51cto.com/5062777/1754809
		ATS/CDN blog
		http://blog.csdn.net/tao_627/article/details/48223565
		�򵥹�������
		http://www.cnblogs.com/shytong/p/5456698.html
	}
	
	NGX������־���� http://blog.csdn.net/gaojinshan/article/details/38399347
	
	IO2{
		�������������첽http://www.cnblogs.com/Anker/p/3254269.html
		select/poll/epoll
		http://www.cnblogs.com/lianzhilei/p/6029100.html
		
		�첽:
		������ :������Ҫԭ�������ڻ�������
		http://www.cnblogs.com/inevermore/p/4046283.html
	}
	
	c��Ƕ��� __asm__{
		http://blog.csdn.net/robbie1314/article/details/6329329
	}
	
	�Ĵ���{
		http://www.cnblogs.com/qq78292959/archive/2012/07/20/2600865.html
	}
	
	Nginx+CGI�������{
		һ�㳣������վ������apache+tomcat+���ݿ�
		����Ngix+tomcat+���ݿ�����������ܹ�������Ǵ�����վӦ�ã����滹����һ��Ӳ�����ؾ���F5��
		php http://blog.csdn.net/dyllove98/article/details/41120789
		C
		http://blog.csdn.net/allenlinrui/article/details/19419721
		http://blog.chinaunix.net/uid-11344913-id-3192736.html
	}
	
	apache nginx�Ƚ�{
		http://www.cnblogs.com/huangye-dream/p/3550328.html
	}
	
	powershell{
		Set-ExecutionPolicy -Scope CurrentUser REMOTESIGNED
	}
	
	������յ����нű������������ִ�У������û����Կ�������ǰ�˴���
	
	�ں˻�����{
		��׼IO������
		http://blog.chinaunix.net/uid-26833883-id-3198114.html
		TCP input�������ں˻�������ô���� ->�ں���Ҫ��ζ�ȡ
		ÿ��������·����һ�����ݶ��У�����ö�����������ô�µ��ķ��齫������������Э��ջ���Ϸ���һ�����󣺴�������·��IP���ڴ�IP��TCP��TCP��ע�⵽������󣬲����Ժ�ĳ��ʱ���ش���Ӧ�ķֽڡ�Ӧ�ó���֪��������ʱ�������
	}
	
	getrlimit()/setrlimit(){ //abbr. resource limit
		����getrlimit()����setrlimit()������ָ����Դ�Ĳ������ޡ�
		��Դ������һ��ֵ��һ��ָ���˵�ǰ�������ƣ���һ�������һ�����Ӳ�����ơ�
		�������ܹ���һ�����̸ı䣬ֻҪ��֤��������Ӳ���ơ�
		һ�������ܹ������ܹ����صģ���������Ӳ�����ƣ�ǰ���Ǵ��ڵ��������ơ�
		http://blog.csdn.net/stormkey/article/details/5890512
	}
	
	buf_t����{
		����
		http://www.tuicool.com/articles/r6ZnUfF
	}
	
	*ԭ�Ӳ���
	
	*iovec{
		ɢ�����;ۼ�д
	}
	
	*iocp{
		IOCP��I/O Completion Port��,����I/O��ɶ˿ڡ� IOCPģ������һ��ͨѶģ�ͣ�������(�ܿ��Ʋ���ִ�е�)�߸��ط�������һ��������
		�ص�IO[overlapped I/O]��Win32��һ����������Ҫ�����ϵͳΪ�㴫�����ݣ������ڴ������ʱ֪ͨ�㡣��Ҳ����[���]�ĺ��塣
		����ϵͳ�ڲ��������߳������overlapped I/O��
		��ɶ˿�����ν��[�˿�]������������TCP/IP�����ᵽ�Ķ˿ڣ�����˵����ȫû�й�ϵ��IOCPֻ�������������ж�д���������ļ�I/O������Щ���ơ�
		�� ����ά���ظ�ʹ�õ��ڴ�ء�(���ص�I/O�����й�)
	������ ȥ��ɾ���̴߳���/�սḺ����
	������ ���ڹ��������̣߳����Ʋ�������С�����߳��������л���
	������ �Ż��̵߳��ȣ����CPU���ڴ滺��������ʡ�
	}
	
	MIME{
		MIME(Multipurpose Internet Mail Extensions)����;�������ʼ���չ���͡�
		���趨ĳ����չ�����ļ���һ��Ӧ�ó������򿪵ķ�ʽ���ͣ�������չ���ļ������ʵ�ʱ����������Զ�ʹ��ָ��Ӧ�ó������򿪡�
	}
	
	sizeof{
		c99��׼ǰ 
		sizeof�ļ��㷢���ڱ���ʱ�̣����������Ա������������ʽʹ��
		ָ�룺32λΪ 4�� 64λ Ϊ 8
	}
	
	spin lock: ������{
		�ȴ����̻�������ռ��CPU��������Ӧ�����ٶȸ��졣
		�ʺϴ���ʱ��̵������
		��Դ���ж������ķ��ʣ���������������
		������ֻ�����ں˿���ռ��ദ�����������Ҫ
	}
	
	on-the-fly{
		���������
	}
	
	������{
		 �����ļ������NAT�������ַת����Э�飬ͨ��һ�����������ط���Internet
		 ʹ��NATЭ�飬�������ڵļ�������Է���Internet�ϵļ��������Internet�ϵļ�����޷����ʾ������ڵļ������
		*NAT{
			PPP
		}
		NAPT Network Address Port Translation{
			�ɽ�����ڲ���ַӳ��Ϊһ���Ϸ�������ַ�����Բ�ͬ��Э��˿ں��벻ͬ���ڲ���ַ���Ӧ
			<�ڲ���ַ+�ڲ��˿�>��<�ⲿ��ַ+�ⲿ�˿�>֮���ת��
		}
	}
	
	CIDR{
		��������·�ɣ�Classless Inter-Domain Routing
		��һ����Internet�ϴ������ӵ�ַ�ķ�������Щ��ַ�ṩ�������ṩ�̣�ISP��������ISP������ͻ���
		 CIDR����8~30λ�ɱ�����ID��������A-B-C������ID���õĹ̶���8��16��24λ��
	}
	
	cookie{
		������get����post����http����ͷ�������cookie��
		Set��Cookie: NAME=VALUE��Expires=DATE��Path=PATH��Domain=DOMAIN_NAME��SECURE
		Cookie ��һС���ı���Ϣ���������û������ҳ���� Web �������������֮�䴫�ݡ��û�ÿ�η���վ��ʱ��Web Ӧ�ó��򶼿��Զ�ȡ Cookie ��������Ϣ��
		ָĳЩ��վΪ�˱���û���ݡ����� session ���ٶ��������û������ն��ϵ����ݣ�ͨ���������ܣ���
		������ RFC2109 �� 2965 �еĶ��ѷ���������ȡ���Ĺ淶�� RFC6265
		һ���û��Ӹ���վ��������˳���Cookie �ɴ洢���û����ص�Ӳ���� ������ Cookies ���� Persistent Cookies��
		ͨ������£����û�����������Ựʱ��ϵͳ����ֹ���е� Cookie��
		Cookie ������ HTML �ļ����������֮ǰ���ã�
		��ͬ������� (Netscape Navigator��Internet Explorer) �� Cookie �Ĵ���һ�£�
		ʹ��ʱһ��Ҫ���ǣ��ͻ����û�������ý�ֹ Cookie���� Cookie ���ܽ����� 
		�����ڿͻ��ˣ�һ��������ܴ����� Cookie �������Ϊ 300 ��������ÿ�����ܳ��� 4KB��
		ÿ�� Web վ�������õ� Cookie �������ܳ��� 20 ��
	}
	
	route{
		Route����������ʾ���˹���Ӻ��޸�·�ɱ���Ŀ�ġ�
		���������һ�㶼��פ����ֻ����һ̨·�����������ϡ�
		����ֻ��һ̨·��������˲�����ʹ����һ̨·���������ݰ�����Զ�̼������ȥ�����⣬
		��·������IP��ַ����Ϊ�����������м������ȱʡ���������롣 
		���ǣ���������ӵ����������·����ʱ����Ͳ�һ����ֻ����ȱʡ�����ˡ�
		ʵ����������������ĳЩԶ��IP��ַͨ��ĳ���ض���·���������ݣ�
		��������Զ��IP��ͨ����һ��·���������ݡ�
	}
	
	״̬��state machine{
		http://blog.csdn.net/eager7/article/details/8517827/
		״̬Ǩ��ͼ��STD��
	}
	
	ѧϰ��Ŀ�������Ҫ ����Nginx �� ����Nginx�Զ���ģ�� �Դﵽһ���Ĺ���
	
	������thrashing���ǲ�������ļ�������ͨ������Ϊ�ڴ��������Դ�ľ������޶��޷������Ҫִ�еĲ�����
	
	multiplexing{
		��·���û�����ָ���̶߳�����
		��·���ã�ʱ��/Ƶ�� һ���ŵ�����·��Ϣ ��
	}
	
	SSI{
		Server Side Includes ��������Ƕ��
		SSI������HTML�ļ��У�����ͨ��ע���е��õ������ָ�롣SSI����ǿ��Ĺ��ܣ�ֻҪʹ��һ���򵥵�SSI ����Ϳ���ʵ��������վ�����ݸ��£�ʱ������ڵĶ�̬��ʾ���Լ�ִ��shell��CGI�ű�����ȸ��ӵĹ��ܡ�
		�о�����һ�ֶ�̬��ҳ������
		��;
		1����ʾ�������˻�������<#echo>
		2�����ı�����ֱ�Ӳ��뵽�ĵ���<#include>
		3����ʾWEB�ĵ������Ϣ<#flastmod #fsize> �����ļ���������/��С�ȣ�
		4��ֱ��ִ�з������ϵĸ��ֳ���<#exec>(��CGI��������ִ�г���
		5������SSI��Ϣ��ʾ��ʽ<#config>�������ļ���������/��С��ʾ��ʽ�� �߼�SSI<XSSI>�������ñ���ʹ��if������䡣[2]  
	}
	
	ABI&API{
		API������Դ����Ϳ�֮��Ľӿڣ����ͬ���Ĵ��������֧�����API���κ�ϵͳ�б���
		Ȼ��ABI�������õ�Ŀ�������ʹ�ü���ABI��ϵͳ������Ķ���������
		ABI�����˸���ϸ��,��APIֻҪ��������ü���
	}
	
	IO{
		��Linux/UNIX �£�������������I/O ������ʽ��
		1.���� I/O
		2.������ I/O
		3.I/O ��·����
		4.�ź����� I/O��SIGIO��
		5.�첽 I/O
	}
	
	STDIN_FILENO {
		/* Standard file descriptors.  */
		#define STDIN_FILENO    0       /* Standard input.  */
		#define STDOUT_FILENO   1       /* Standard output.  */
		#define STDERR_FILENO   2       /* Standard error output.  */
	}
	
	memory pool/slab{
		pool�ڴ����������ʹ���ڴ�֮ǰ�����������һ�������ġ���С���(һ�������)���ڴ���������á�
		��Ҫ��ֹ��Ƭ����
		
		slab{
			һ�����С�ڴ������ڴ������� 
			�봫ͳ���ڴ����ģʽ��ȣ� slab ����������ṩ�˺ܶ��ŵ㡣
			1���ں�ͨ�������ڶ�С����ķ��䣬���ǻ���ϵͳ���������ڽ��������η��䡣
			2��slab ���������ͨ�������ƴ�С�Ķ�����л�����ṩ���ֹ��ܣ��Ӷ������˳�������Ƭ���⡣
			3��slab ��������֧��ͨ�ö���ĳ�ʼ�����Ӷ�������ΪͬһĿ�Ķ���һ�������ظ����г�ʼ����
			4��slab ������������֧��Ӳ������������ɫ��������ͬ�����еĶ���ռ����ͬ�Ļ����У��Ӷ���߻���������ʲ���ø��õ����ܡ�
		}
	}

	�첽������->select/poll/epoll ; kqueue
	int select( int nfds, fd_set FAR* readfds,��fd_set * writefds, fd_set * exceptfds,��const struct timeval * timeout){
		nfds����һ������ֵ����ָ�����������ļ��������ķ�Χ���������ļ������������ֵ��1�����ܴ���Windows�����������ֵ����ν���������ò���ȷ��
		readfds������ѡ��ָ�룬ָ��һ��ȴ��ɶ��Լ����׽ӿڡ�
		writefds������ѡ��ָ�룬ָ��һ��ȴ���д�Լ����׽ӿڡ�
		exceptfds������ѡ��ָ�룬ָ��һ��ȴ���������׽ӿڡ�
		timeout��select()���ȴ�ʱ�䣬������������ΪNULL��
		
		FD CONTROLS{
			��socket.hͷ�ļ��й��������ĸ��������������ּ���
			FD_SETSIZE��������ȷ��һ������������ж��������֣�FD_SETSIZEȱʡֵΪ64�����ڰ���socket.hǰ��#define FD_SETSIZE���ı��ֵ����
			�����ڲ���ʾ��fd_set����ʾ��һ���׽ӿڵĶ��У����һ����ЧԪ�صĺ���Ԫ��ΪINVAL_SOCKET��
			��Ϊ��
			FD_CLR(s,*set)���Ӽ���set��ɾ��������s��
			FD_ISSET(s,*set)����sΪ������һԱ�����㣻����Ϊ�㡣
			FD_SET(s,*set)���򼯺����������s��
			FD_ZERO(*set)����set��ʼ��Ϊ�ռ�NULL��
		}
	}
	poll -> epoll{
		Linux�е��ַ��豸��������һ������
		unsigned int (*poll)(struct file * fp, struct poll_table_struct * table){
			�˺�����ϵͳ����select�ڲ���ʹ�ã������ǰѵ�ǰ���ļ�ָ��ҵ��豸�ڲ�����ĵȴ�
		}
		int poll(struct pollfd fds[], nfds_t nfds, int timeout){
			fds����һ��struct pollfd�ṹ���͵����飬���ڴ����Ҫ�����״̬��Socket��������ÿ�������������֮��ϵͳ�������������飬���������ȽϷ��㣻�ر��Ƕ���socket���ӱȽ϶������£���һ���̶��Ͽ�����ߴ����Ч�ʣ���һ����select()������ͬ������select()����֮��select()�����������������socket���������ϣ�����ÿ�ε���select()֮ǰ�������socket���������¼��뵽�����ļ����У���ˣ�select()�����ʺ���ֻ���һ��socket���������������poll()�����ʺ��ڴ���socket�������������
			nfds��nfds_t���͵Ĳ��������ڱ������fds�еĽṹ��Ԫ�ص���������
			timeout����poll��������������ʱ�䣬��λ�����룻
		}
		struct pollfd {
			int fd; /*�ļ�������*/
			short events; /* �ȴ�����Ҫ�����¼� */
			short revents; /* ʵ�ʷ����˵��¼���Ҳ���Ƿ��ؽ�� */
		};
	}
	epoll{
		Linux�ں�Ϊ����������ļ������������˸Ľ���poll����Linux�¶�·����IO�ӿ�select/poll����ǿ�汾
		�������������������������������ֻҪ������Щ���ں�IO�¼��첽���Ѷ�����Ready���е����������Ͼ�����
		epoll�����ṩselect/poll����IO�¼���ˮƽ������Level Triggered���⣬���ṩ�˱�Ե������Edge Triggered��
	}
	->ˮƽ����&��Ե����{
		ˮƽ����:����ļ��������Ѿ��������Է�������ִ��IO������,��ʱ�ᴥ��֪ͨ.
		����������ʱ���ظ����IO��״̬,û�б�Ҫÿ�������������󾡿��ܶ��ִ��IO.
		select,poll������ˮƽ����.
		��Ե����:����ļ����������ϴ�״̬�ı�����µ�IO�����,��ʱ�ᴥ��֪ͨ.
		���յ�һ��IO�¼�֪ͨ��Ҫ�����ܶ��ִ��IO����,��Ϊ�����һ��֪ͨ��û��ִ����IO��ô����Ҫ�ȵ���һ���µ�IO��������ܻ�ȡ��������������.
		�ź�����ʽIO�����ڱ�Ե����.
		
		->>
			ˮƽ����:Ҳ����ֻ�иߵ�ƽ(1)��͵�ƽ(0)ʱ�Ŵ���֪ͨ,ֻҪ��������״̬���ܵõ�֪ͨ.�����ᵽ��ֻҪ�����ݿɶ�(����������)��ôˮƽ������epoll����������.
			��Ե����:ֻ�е�ƽ�����仯(�ߵ�ƽ���͵�ƽ,���ߵ͵�ƽ���ߵ�ƽ)��ʱ��Ŵ���֪ͨ.�����ᵽ��ʹ�����ݿɶ�,����û���µ�IO�����,epollҲ������������.
		comment: ÿ��ֻҪ�ɶ�д�Ͷ�д �� �������¿ɶ�д�¼�����Ȼ��ʹ֮ǰ��û����Ҳ����д��
	}
	EAGAIN

	URI/URL{
		URI �Ǵ������·����ʼ��
		URL����������
		��URL http://zhidao.baidu.com/question/68016373.html  
		URI ��/question/68016373.html
		�ڰڶ��Ǳ߷������ϰ�http://zhidao.baidu.com/�������������·��
		�ĸ�
	}

	�ٷ�Nginx+���ĵ��Ƚ���ϸ��Nginx+��Nginx�������{
		Nginx+��Nginx��Դ������Ļ����ϣ���������ҵ�������ԣ����磺

		ȫ���ܵ�HTTP��TCP���ؾ���
		�����ܵķ������
		��̬���ݺͶ�̬���ݵĻ����ж��
		����Ӧ��ý��̸�����Ƶ���ݵ������豸
		��Ӧ�����еĽ������͸߿�����
		�ṩ�Ǳ���API��ʽ�ĸ߼�����
		�߼���غ͹����ṩ�Կ������ѺõĹ����������ʵʱ�ı��
		�Ự�־���
		��ѯ����

	}

	X-Forwarded-For{
		
	}

	c++���ڴ����{
		����ڴ���� 
	��C++�У��ڴ�ֳ�5���������Ƿֱ��Ƕѡ�ջ�����ɴ洢����ȫ��/��̬�洢���ͳ����洢���� 
	ջ��������Щ�ɱ���������Ҫ��ʱ����䣬�ڲ���Ҫ��ʱ���Զ�����ı����Ĵ洢��������ı���ͨ���Ǿֲ����������������ȡ� 
	�ѣ�������Щ��new������ڴ�飬���ǵ��ͷű�������ȥ�ܣ������ǵ�Ӧ�ó���ȥ���ƣ�һ��һ��new��Ҫ��Ӧһ��delete���������Աû���ͷŵ�����ô�ڳ�������󣬲���ϵͳ���Զ����ա� 
	���ɴ洢����������Щ��malloc�ȷ�����ڴ�飬���Ͷ���ʮ�����Ƶģ�����������free�������Լ��������ġ� 
	ȫ��/��̬�洢����ȫ�ֱ����;�̬���������䵽ͬһ���ڴ��У�����ǰ��C�����У�ȫ�ֱ����ַ�Ϊ��ʼ���ĺ�δ��ʼ���ģ���C++����û����������ˣ����ǹ�ͬռ��ͬһ���ڴ����� 
	�����洢��������һ��Ƚ�����Ĵ洢�������������ŵ��ǳ������������޸ģ���Ȼ����Ҫͨ���������ֶ�Ҳ�����޸ģ����ҷ����ܶ࣬�ڡ�const��˼����һ���У��Ҹ�����6�ַ����� 

	��ȷ���ֶ���ջ 
	��bbs�ϣ�����ջ���������⣬�ƺ���һ������Ļ��⣬�ɴ˿ɼ�����ѧ�߶Դ������ǻ�������ģ������Ҿ���������һ�������� 
	���ȣ����Ǿ�һ�����ӣ� 
	void f() { int* p=new int[5]; } 
	�����̶̵�һ�仰�Ͱ����˶���ջ������new���������Ⱦ�Ӧ���뵽�����Ƿ�����һ����ڴ棬��ôָ��p�أ����������һ��ջ�ڴ棬������仰����˼���ǣ���ջ�ڴ��д����һ��ָ��һ����ڴ��ָ��p���ڳ������ȷ���ڶ��з����ڴ�Ĵ�С��Ȼ�����operatornew�����ڴ棬Ȼ�󷵻�����ڴ���׵�ַ������ջ�У�����VC6�µĻ��������£� 
	00401028 push 14h 
	0040102A call operator new (00401060) 
	0040102F add esp,4 
	00401032 mov dword ptr [ebp-8],eax 
	00401035 mov eax,dword ptr [ebp-8] 
	00401038 mov dword ptr [ebp-4],eax 
	�������Ϊ�˼򵥲�û���ͷ��ڴ棬��ô����ôȥ�ͷ��أ���delete pô���ģ����ˣ�Ӧ����delete []p������Ϊ�˸��߱���������ɾ������һ�����飬VC6�ͻ������Ӧ��Cookie��Ϣȥ�����ͷ��ڴ�Ĺ����� 
	���ˣ����ǻص����ǵ����⣺�Ѻ�ջ������ʲô���� 
	��Ҫ�����������¼��㣺 
	1������ʽ��ͬ�� 
	2���ռ��С��ͬ�� 
	3���ܷ������Ƭ��ͬ�� 
	4����������ͬ�� 
	5�����䷽ʽ��ͬ�� 
	6������Ч�ʲ�ͬ�� 
	����ʽ������ջ���������ɱ������Զ��������������ֹ����ƣ����ڶ���˵���ͷŹ����ɳ���Ա���ƣ����ײ���memory leak�� 
	�ռ��С��һ��������32λϵͳ�£����ڴ���Դﵽ4G�Ŀռ䣬������Ƕ��������ڴ漸����û��ʲô���Ƶġ����Ƕ���ջ������һ�㶼����һ���Ŀռ��С�ģ����磬��VC6���棬Ĭ�ϵ�ջ�ռ��С��1M�������ǣ��ǲ�����ˣ�����Ȼ�����ǿ����޸ģ� 
	�򿪹��̣����β����˵����£�Project->Setting->Link����Category ��ѡ��Output��Ȼ����Reserve���趨��ջ�����ֵ��commit�� 
	ע�⣺reserve��СֵΪ4Byte��commit�Ǳ����������ڴ��ҳ�ļ����棬�����õĽϴ��ʹջ���ٽϴ��ֵ�����������ڴ�Ŀ���������ʱ�䡣 
	��Ƭ���⣺���ڶ�������Ƶ����new/delete�Ʊػ�����ڴ�ռ�Ĳ��������Ӷ���ɴ�������Ƭ��ʹ����Ч�ʽ��͡�����ջ�������򲻻����������⣬��Ϊջ���Ƚ�����Ķ��У���������˵�һһ��Ӧ����������Զ����������һ���ڴ���ջ�м䵯������������֮ǰ����������ĺ����ջ�����Ѿ�����������ϸ�Ŀ��Բο����ݽṹ���������ǾͲ���һһ�����ˡ� 
	�������򣺶��ڶ��������������������ϵģ�Ҳ���������ڴ��ַ���ӵķ��򣻶���ջ�����������������������µģ��������ڴ��ַ��С�ķ��������� 
	���䷽ʽ���Ѷ��Ƕ�̬����ģ�û�о�̬����Ķѡ�ջ��2�ַ��䷽ʽ����̬����Ͷ�̬���䡣��̬�����Ǳ�������ɵģ�����ֲ������ķ��䡣��̬������alloca�������з��䣬����ջ�Ķ�̬����Ͷ��ǲ�ͬ�ģ����Ķ�̬�������ɱ����������ͷţ����������ֹ�ʵ�֡� 
	����Ч�ʣ�ջ�ǻ���ϵͳ�ṩ�����ݽṹ����������ڵײ��ջ�ṩ֧�֣�����ר�ŵļĴ������ջ�ĵ�ַ��ѹջ��ջ����ר�ŵ�ָ��ִ�У���;�����ջ��Ч�ʱȽϸߡ�������C/C++�������ṩ�ģ����Ļ����Ǻܸ��ӵģ�����Ϊ�˷���һ���ڴ棬�⺯���ᰴ��һ�����㷨��������㷨���Բο����ݽṹ/����ϵͳ���ڶ��ڴ����������õ��㹻��С�Ŀռ䣬���û���㹻��С�Ŀռ䣨�����������ڴ���Ƭ̫�ࣩ�����п��ܵ���ϵͳ����ȥ���ӳ������ݶε��ڴ�ռ䣬�������л���ֵ��㹻��С���ڴ棬Ȼ����з��ء���Ȼ���ѵ�Ч�ʱ�ջҪ�͵öࡣ 
	���������ǿ��Կ������Ѻ�ջ��ȣ����ڴ���new/delete��ʹ�ã�������ɴ������ڴ���Ƭ������û��ר�ŵ�ϵͳ֧�֣�Ч�ʺܵͣ����ڿ��������û�̬�ͺ���̬���л����ڴ�����룬���۱�ø��Ӱ�������ջ�ڳ�������Ӧ����㷺�ģ������Ǻ����ĵ���Ҳ����ջȥ��ɣ��������ù����еĲ��������ص�ַ��EBP�;ֲ�����������ջ�ķ�ʽ��š����ԣ������Ƽ���Ҿ�����ջ���������öѡ� 
	��Ȼջ������ڶ�ĺô����������ںͶ���Ȳ�����ô����ʱ�����������ڴ�ռ䣬�����öѺ�һЩ�� 
	�����Ƕѻ���ջ����Ҫ��ֹԽ������ķ������������ǹ���ʹ��Խ�磩����ΪԽ��Ľ��Ҫô�ǳ��������Ҫô�Ǵݻٳ���Ķѡ�ջ�ṹ���������벻���Ľ��,����������ĳ������й����У�û�з�����������⣬�㻹��ҪС�ģ�˵����ʲôʱ��ͱ�������ʱ��debug�����൱���ѵģ��� 
	���ˣ�����һ���£�������˰Ѷ�ջ������˵����������˼��ջ���ɲ��Ƕѣ��Ǻǣ�����ˣ�
	}

	�����ڴ�һ��ķ���{
		����һ�����̵��ڴ�ռ���ԣ��������߼��Ϸֳ�3�����ݣ�����������̬�������Ͷ�̬����������̬������һ����ǡ���ջ������ջ (stack)���͡���(heap)�������ֲ�ͬ�Ķ�̬��������ջ��һ�����Խṹ������һ����ʽ�ṹ�����̵�ÿ���̶߳���˽�еġ�ջ��������ÿ���߳���Ȼ ����һ���������ر��������ݶ��ǻ������š�һ����ջ����ͨ��������ַ���͡�ջ������ַ��������ȫ�ֱ����;�̬���������ھ�̬�����������ر��������ڶ�̬�� ����������ջ�С�����ͨ����ջ�Ļ���ַ��ƫ���������ʱ��ر�����

		�����������������ȵͶ��ڴ����� 
		�� ���� �� 
		������������������ 
		�� ��̬������ �� 
		������������������ 
		�� ���� �� 
		������������������ 
		�� ������ �� 
		������������������ 
		�� ��̬������ �� 
		������������������ 
		�� ���� �� 
		�����������������ȸ߶��ڴ�����
	}

	Cache{
		���ٻ���洢��(Cache Memory)
		�ڴ�����ϵͳ���ߵ�ʱ��Ƶ�ʹ����ģ����Ƶ��ͨ��Ҳ����CPU����Ƶ(�������񡢶���ϵ�еĴ���������������Ʋ�����DDR������CPU��������ƵΪϵͳ����Ƶ�ʵ�����)�����ǣ�CPU�Ĺ���Ƶ��(��Ƶ)����Ƶ�뱶Ƶ���ӵĳ˻�
		֪��һ��Cache��ΪL1 Cache(�����ַ�Ϊ����Cache������Cache)��L2 Cache������
	}

	___cdecl{
		__cdecl ��C Declaration����д
		��ʾC����Ĭ�ϵĺ������÷��������в������ҵ���������ջ����Щ�����ɵ������������Ϊ�ֶ���ջ�������ú�������Ҫ������ߴ��ݶ��ٲ����������ߴ��ݹ�����߹��ٵĲ�����������ȫ��ͬ�Ĳ����������������׶εĴ���
	}

	ISA{
		Internet Security and Acceleration
		ssl���
	}

		
	yum{
		list all
		{rpm -qi/-ql + xxx}
	}
}

*dailycode{
	��code����Ȩ����Щ���ߺ������Ա���������
	*һ����hash
	*���ƽ���/�߳��� half
	*������Է���������߸���/�߲�����ģ��
	*base64 en/decode
	*���ܷ���
	*�첽�������¼����
	*ָ����С���ļ�������
	*nginx - upstream ���ļ����󣬹ܵ�ģʽ
	*���ؾ����㷨{
		http://www.tuicool.com/articles/RJzM7rF
	}
	*�ں˻�����͵�� http://blog.csdn.net/stpeace/article/details/45009927
	*myHomePage
	*level/edge sample test
	*dailycode:�����������������/������ȱ���
	*���û�ע���¼ϵͳ
	*http���ķ���
	*�������˷�����
	*�������
	*�Ŵ��㷨ʵ��
	��ӡ�ṹ�͸��ִ� done? -��ӡ��������ʼ�ĵ�ַ
	*�ڴ�״̬���ƹ���
	*����cpu��ռ����
	*����ѧϰ�����˹����
	*UnitTest���
	*ռ���ڴ�̽��
	
}
*weeklyblog{
	*����򵥵��״�֪ʶ�����緵��ʱ�Ŀ�������������ʽ����
	*�����7����������
	*����ϵͳ֪ʶ����
	*�㷨�����ݽṹ֪ʶ����
	*RPC֪ʶ����
	*���������֪ʶ����
	*����������ʽ
	*ʱ�������߲�������̿��� ���̵߳ļ��������ڵ��߳�״̬����
	*����֪ʶ�ķ��� ��/��
	ѧУ�ľ��� - ���ݣ� ѧ���� ���£�
	
}

*todo{
    Study{
        
        ip�����еĸ�����˼{
            linux ϵͳ���� ����̳�
            https://www.cyberciti.biz/faq/linux-ip-command-examples-usage-syntax/
            
            ip a del 192.168.85.200/32 dev lo
        }
        
        linux api{
            ���塢���������Ų�ѯ
            http://elixir.free-electrons.com/linux/v2.6.32.57/ident/ip_vs_get_vip_groups
            ��������{
                ioctl()
            }
            
        }
        
        �Ǹ���������{
            ���¹Ǹ�������ʳ��ڴ���2013.7.17CNNIC������
            ��Ҫ�Ǹ�������ʳ��ڴ�����
            
            ���ʳ��ڴ�������Mbps��
            �й����� 1,118,249
            �й���ͨ 677,205
            �й��ƶ� 244,594
            �й������Ϳ��м������ 35,500
            �й��Ƽ��� 22,600
            �й����ʾ���ó�׻����� 2
            �ϼ� 2,098,150
        }
        
        ES{
            elastic stack
            elk
            elasticsearch(ES)����+ logstash���ݲɼ� + kibanaǰ��
            cloud
            
            ES ����lucene��javaʵ�֣��ṩRESTful API 
            
            ��������
            doc es������λ������json
            index ����feature doc set
            type: logic
            filed: �ֶ�
            
            es ���ϵ�����ݿ⣬���ݿ�Ϊ��������Ϊ���ͣ���Ϊ�ĵ�����Ϊ��
            
            log stash:
            ʵʱ���롢������������ݵ������ռ�����
            jruby
            input(plugin)-filter-output(plugin)
            tags��ʾƥ���Ƿ�ɹ���
            
            beats ϵ�й���: (golang?)
            file,packet,metric,heart,winlog beat 
            
            filebeat:
            prospectctor
            ÿ����־����һ��harvester��أ�
            spooler�ռ���Ȼ���͵��ض� ����
            
            kibana:
            �ṩ���ݷ�����ǰ��չʾ����
            
            ǰ��ʹ�ã�
            �����﷨��
            �ֶ����� ��������ģ��ƥ�䣬����Ϊ��ȷ
            ȫ��������ֱ����
            ͨ���ƥ�䵥���ַ�?, *ƥ����
            ��Χ���� code:[a to b] cod:>499
            ���Ӵ� AND/OR
            
            VISUALIZE���ӻ�����
            
            ���ó�����
            ��վ�����������ݹؼ��ʸ������۴̡���������
            ���ģ��־ʵʱ���ݷ���
            
            concept:
            beats series
            kafka
            Storm��Ⱥ��
            es 5~6 00 million
            ipʶ�𹤾ߣ�ip��
            
            Note:
            fields�еİٷֱȲ�����ȫ�ģ�ֻ�����500��
            
            
            Q:
            �߼����ʣ� AND OR + - (NOT)
            ��̨�����ݴ洢��ʽ��
            log stash���Դ����ݣ�����ES��
        }

        lvs, linux����{
            - lsmod
            - keepalived
            - ipvsadm
            - arp�㲥
            - ·��ԭ��
            - VRRP
            - ICMP
            - /var/log/messages
            - VIP����������
            {
                - ת����
                - echo 1 > /proc/sys/net/ipv4/ip_forward
            - Broadcast Address
                - x.x.x.255
                - ֱ�ӹ㲥�����޹㲥 	
                - �����ֻ��UDP���Թ㲥
                - ��winsockʵ����, ��һ��ѡ���Ӧ�Ƿ�����㲥.
            �������setsockopt�򿪸�ѡ��.
                - . �򿪺�, ��sendto��255.255.255.255���͵����ݰ�ȫ���㲥.
                - �Ϸ��Ĺ㲥��ַ���������������ַ�������������š������ַͨ��������ip��ַ���������밴λ��ó���������ip��ַΪ10.78.202.175 ����������Ϊ255.0.0.0
            - DHCP
                - DHCP��Dynamic Host Configuration Protocol����̬��������Э�飩��һ��������������Э�飬ʹ��UDPЭ�鹤���� ��Ҫ��������;�����ڲ�������������Ӧ���Զ�����IP��ַ�����û������ڲ��������Ա��Ϊ�����м���������������ֶ�
                - DHCP��3���˿ڣ�����UDP67��UDP68Ϊ������DHCP����˿ڣ��ֱ���ΪDHCP Server��DHCP Client�ķ���˿ڣ�546�Ŷ˿�����DHCPv6 Client����������DHCPv4����ΪDHCP failover����������Ҫ�ر����ķ���DHCP failover����������˫���ȱ�����


            - RESTful API
                - Representational state transfer
                - ��Roy Fielding�Ĳ�ʿ������ϸ��10�飬�������߰�����鶼���ÿ�

            - ����ѧϰ��ÿ�ֶ���ѧһ����Դ�ģ������Ĺ�ע�ص�
            - linux��������
                - ifconfig�ǲ鿴����������Ϣ����ifconfig eth0 ip ������eth0��ip��ַ�� route add default gw IP �����Ĭ�����أ�ifdown eth0,�ǹر�������ifup eth0�Ǽ��Ҳ������/etc/sysconfig/network-scripts/ifcfg-eth0����������ã��ղ���Щ�������ʱ���ã�����/etc/sysconfig/network-scripts/ifcfg-eth0��������������õ�
                - �о�Ҫ��̫���ˣ�Ӧ��Ū���ֲ�

                - ��Ҫ����
                    - IP��ַ
                    - ��������
                    - �����ַ��IP+�������㣩
                    - ���أ�����ںͳ��ڣ�

            - arpЭ��
                - ��ַ����Э�飬��ARP��Address Resolution Protocol�����Ǹ���IP��ַ��ȡ�����ַ��һ��TCP/IPЭ��
                - Ϊʹ�㲥����С��ARPά��IP��ַ��MAC��ַӳ��Ļ����Ա㽫��ʹ�á�ARP������԰�����̬�;�̬��Ŀ����̬��Ŀ��ʱ�������Զ���Ӻ�ɾ����ÿ����̬ARP�������Ǳ������������10���ӡ��¼ӵ������е���Ŀ����ʱ��������ĳ����Ŀ��Ӻ�2������û����ʹ�ã������Ŀ���ڲ���ARP������ɾ�������ĳ����Ŀ����ʹ�ã������յ�2���ӵ��������ڣ����ĳ����Ŀʼ����ʹ�ã���������յ�2���ӵ��������ڣ�һֱ��10���ӵ���������ڡ���̬��Ŀһֱ�����ڻ����У�ֱ���������������Ϊֹ��
                
                - ��ַ224.0.0.0~224.0.0.255,���ھ�������·������ת�����ڴ˷�Χ��IP����·�����������ӵ�ַ�������£�
                

                224.0.0.1�C�ڱ�������������ϵͳ
                
                224.0.0.2�C�ڱ�������������·����
                
                224.0.0.5�COSPF ·����
                
                224.0.0.6�COSPF ָ��·����
                
                224.0.0.9�CRIPv2 ·����
                
                224.0.0.10�CIGRP ·����
                
                224.0.0.13�CPIMv2 ·����

            - �����ж�
                - �������۷���������۷����������۷�
                - ��ȷ������ɣ����ܴ𰸼�����ϵ��
            - whois

            - yum
                - yum search whois
                - yum whatprovides whois
                - yum whatprovides */bin/whois*

            - NAT������ת����ת������
            -	 NAT���ÿ��Է�Ϊ��̬��ַת������̬��ַת�������ö�̬��ַת��
                - ����ͨ���ӿ���ת��
                - ע�⣺������û�ͬʱʹ��һ��IP��ַ���ⲿ����ͨ��·�����ڲ������ϲ����TCP��UDP�˿ںŵ�Ψһ��ʶĳ̨�������
            - ·�����ͻ��������ӹ���
                - ·��ϵͳOpenWRT
            - �����������ӹ���

            - ifconfig����

                - UP BROADCAST RUNNING SLAVE MULTICAST
                    - Linux bonding ����ģʽslave�����л�
                    - http://www.cnblogs.com/dkblog/p/3613407.html
                    - 
                - MTU��Maximum Transmission Unit����д����˼�������ϴ��͵�������ݰ�����λ���ֽڡ���ͬ�Ľ��뷽ʽ��MTUֵ�ǲ�һ���ģ����ֵ̫��ͻ�����ܶ����ݰ���Ƭ�����Ӷ����ʣ����������ٶȡ�����ƽ��ʹ�õĿ��PPPoE���ӷ�ʽ����MTUֵ���Ϊ1492

            - keepalived redhat�ֲ�
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
        
        ���ݿ�Ĳ�����������
        
        DNS֪ʶ{
            ����
            BIND(Berkley Inet Name Domain)
        }
        ��Ϸ��������С���ݣ����ǵ��ӳٵ�ʵ��{
            ���ӳٵĲ���
        }
        
        mp4��ʽϸ��{
            box
            ֡��Ϣ��ʱ����Ϣ���ؼ�֡
            ���������桢ͬ��
        }
        
        influxdb{
            - database
            - measurement like table in SQL
            - tag indexed; field is not
        }
        
        crontab{
            ����ʱ�䣬�Զ�����
            crontab -e�༭
            -l��ʾ
        }
        
        �����첽��{
            libev,libevent, libuv, proxygen, asio
        }
        
        c++11 lambda{
            [ capture ] ( params ) mutable exception attribute -> ret { body } 	(1) 	 
            [ capture ] ( params ) -> ret { body } 	(2) 	 
            [ capture ] ( params ) { body } 	(3) 	 
            [ capture ] { body } (4)
        }
        
        cgroup{
            �ڵ�����ϣ���첿���򣬷�Ϊ���ࣺ
            1. cache��أ�nginx��cache��io�ܼ�
            2. ͳ����أ�kafaka��ͳ�ơ���־����ȣ�cpu�ܼ���
            ��ҪΪ����������CPU���ġ��ڴ�ĸ���
            
            ���о���cgroupԭ�� �� ʹ���еĹ�����Ҫ��docker��lxc��Щ��ϵͳ��centos6���ο������
            https://access.redhat.com/documentation/zh-CN/Red_Hat_Enterprise_Linux/6/html/Resource_Management_Guide/index.html
        }
    }
    
    �����ݿ�+ҳ����һ���Լ��ĸ�����Ϣ����ϵͳ{
        
        - ��Ϊ������������sqlite
        - һ��ֳɴ��ı��ͷǴ��ı����ݣ���pdf,word��,�����ݣ���һ�仰
        - sqlite �ϴ��������������ݴ��ļ���
    }
    
    
	��ƺ�ʵ������{
		UML��DSL
	}
	
	Automake����/cmake����
    
    awk/linux cmds {
        http://man.linuxde.net/sed
        http://www.cnblogs.com/ggjucheng/archive/2013/01/13/2858470.html
        
        - awk match($1,~/xxx/,a) print a;�� ����
        - sed -i 's/a/b/' filename
        
        {
            1.awk����ʹ��˫���ŵ������
	
            ��ʱ��awk��������ʹ��\"$var\"�Ϳ��������ⲿ����������var��ֵ
            
            $ var="BASH";echo "unix script"| awk "gsub(/unix/,\"$var\")"
            
            2.awk����ʹ�õ����ŵ������
            
            ��ʱ��awk��������ʹ��"'"$var"'"�Ϳ���Ӧ���ⲿ����var��ֵ��ע��������ʾ����˫����֮����һ��������
            
            $ var="BASH";echo "unix script"| awk 'gsub(/unix/, "'"$var"'")'
            BASH script
            
            3.awk�Ĳ���-v  (�Ƽ�)
            
            ���ûʲô�ý��͵ģ�Ӧ�����õñȽ϶��һ�ַ����ˣ�����ʹ��-v�������Ӵ�һ���������丳ֵ
            
            $ echo "unix script"| awk -v var="BASH" 'gsub(/unix/, var)'
            BASH script


              awk��shell��������ֵ

            ����awk��shell���ݱ���������˼���޷�����awk(sed/perl��Ҳ��һ��)���������shell���Ȼ������shellȥִ����Щ���
            
            eval $(awk 'BEGIN{print "var1='str1';var2='str2'"}')
            
            ����eval $(awk '{printf("var1=%s; var2=%s; var3=%s;",$1,$2,$3)}' abc.txt)
            
            ֮������ڵ�ǰshell��ʹ��var1,var2�ȱ����ˡ�
            
            echo "var1=$var1 ----- var2=$var2"
        }
    }
	
	����ࡿ
	http://blog.csdn.net/striver1205/article/details/25695437
	http://blog.chinaunix.net/uid-16459552-id-3328601.html
	��QA��c++ʵ��ϸ�ڣ�
	http://www.oschina.net/question/565065_72355
	��TODO��ATS���ȵ㱣�����ơ�Cache��Ŀ¼���֣��������ҪɾĿ¼����ôά����{
		URI��hash�Ķ�Ӧ��ϵ�Ƕ����ģ�����hash��ֵ�ĸ���x4������Ŀ¼������hash��ײʱ����
	}
	��TODO��APUE thread/thread control
	��TODO��
	�ܽ�׼�������ķ�������
	QQ cache ok
	�߳�ģ��ͼ
	log���
	prefetch ok 
	Э��contiuation
	COSS�����ӶԱ�{
		squid�Ľ��飺С�ļ�ʹ��COSS���ļ�ʹ��ufs
		ATS��ֻ��COSSϵͳ
	}
	�ܽ���ڿɹ������뵽github��
	������ܸ�SVN
	�����磺vim
	��QA��CENTOS���簲ȫ�Ĳ㼶 -> linux ����http://blog.csdn.net/echoisland/article/details/6993756
	��Q����־���ڱ�������
	��Q��ATS ����server��ʱ����һ��server ���� pool?
	
	
	��Q��TS�ڴ滺�滹���˽���ϸ�ṹ
	COSS�����ơ�������
	���ȣ��������ѭ��buff����ôÿ�δ�Ҫ�ҵ����ʵĴ�С����Ӧ�ø���һЩ��
	��һ�νӽ�����֮�󣬺������Ҫ�������ݣ���Ҫɾ�������ݣ��洢�ռ�������Ƭ����ɾ�������ݵ��߼�Ҳ�Ḵ�ӣ���Ȼ����Բο�һ���ڴ�����Ϊʲô�ֲ���COSS��
	
	read while writerҪ������
	֮ǰ�ʼ��е�[?]
	collapsed_forwarding �۵���Դ
	
	[!]ѧϰ�ƻ�{
		Qs{
			�ʼ������ʲ���
		}
		small{
			���̺��߳�
			hash��
			Э�̡��첽�ص����¼�����
			�ڴ桢
		}
		Perl +������
		Python
		ATS���á��ܹ�������
		ATSԴ��
		squidԴ��
		CDN�������
		CDN: NGINX + ATS���ô
		further:{
			CDN����ϵͳ
			CDN�ڵ㽨��
			��IDC�����ڵ�Ĳ���
			��ν������
			�߿�����
			���ܺ�ѹ�����Է�ʽ
			�᲻���а�ȫ���⣬������
		}
		APUE, 
		gdbʹ��{
            http://bbs.chinaunix.net/thread-150524-1-1.html
            follow�ӽ���
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
		coredump����
		Unix�߼������̣�
		Linux����������
		TCP/IP��⣬
		�㷨���ۣ�
		����ϵͳ��
		Apache,
		�ʵ�����ѧ��������ѧ����
		cosi ��ԭ��
	}
	
	Unix������;APUE;CDN���
	linux�ܵ���������δ�����������棿
	
	������ʱ����԰���������ʱ�ڴ�״̬���������ݽṹ�ڴ棬�����ڴ��״̬��ͼʾ����
	��ʵ��ģ��ʵ��
	������������ʵ��
	����Ӧ�߲���ʱ��ʵ�����ģ��

	errno����11(EAGAIN)��������˼error,again ����:Resource temporarily unavailable
		��������ڷ�����ģʽ�µ����������������ڸò���û����ɾͷ����������������󲻻��ƻ�socket��ͬ�������ù������´�ѭ������recv�Ϳ��ԡ��Է�����socket���ԣ�EAGAIN����һ�ִ�����VxWorks��Windows�ϣ�EAGAIN�����ֽ���EWOULDBLOCK��

	
	*�������nginx
	*Ketama Consistent Hash
	
	*SSL & HTTPS
	*X-Forwarded-For
	
	*nginx �ڴ�� http://www.ituring.com.cn/article/17520
	
	*user/kernel space & syscall{
		����״̬��ͬ
		����״̬��ͬ��ϵͳ���õĵ��ù��̺ͱ����ù��������ڲ�ͬ��״̬������ͨ�Ĺ��̵���һ����������ͬ��״̬��[2] 
		���÷�����ͬ
		���÷�����ͬ��ϵͳ���ñ���ͨ�����жϻ������Ƚ���ϵͳ���ģ�Ȼ�����ת����Ӧ������������ͨ���̵��ÿ���ֱ���ɵ��ù���ת�򱻵��ù��̡�[2] 
		��������
		�������⡣�ڲ�������ʽ���ȵ�ϵͳ�У���ϵͳ���÷���ʱ��Ҫ���½��е��ȷ����D�D�Ƿ��и������ȼ��������������ͨ�Ĺ��̵���ֱ�ӷ��ص��ù��̼���ִ�С�
	}
	
	CGI{
		Common Gateway Interface
	}
	
	*Perl normal expression
	*Nagle Algorithm{
		��������ν��С������ķ���
		��δȷ�����ݷ��͵�ʱ���÷������������͵������
		:Nagle�㷨�Ļ�������������ʱ�̣����ֻ����һ��δ��ȷ�ϵ�С�Ρ� ��ν��С�Ρ���ָ����С��MSS�ߴ�����ݿ飬��ν��δ��ȷ�ϡ�����ָһ�����ݿ鷢�ͳ�ȥ��û���յ��Է����͵�ACKȷ�ϸ��������յ���
		�κ�����������ֱ���õ����Ե�����ȷ�ϻ���ֱ���ܵ���һ���������������ٷ�����
		���ַ����ڰ������������ڵ�����������õ����ƹ㣬��Ϊ��Ĭ�ϵ�ִ�з�ʽ��
		�����ڸ߻�����������Щʱ���ǲ���Ҫ�ģ������ڿͻ�/������������
		����������£�nagling����ͨ��ʹ��TCP_NODELAY �׽���ѡ��رա�
	}
	*cmd:netstat
	*configure & automake
	
	Tengine by a team from taobao
	http://tengine.taobao.org/documentation.html
	
	*truncked ����
	
}

knowledge{
    STL{
        ���治�ԣ��ڴ������malloc����
        stl��gcc3.3�Ժ�Ͳ���cache��
        stl�ڴ���ƺ�������ϵͳ�ͷ��Լ����õ��ڴ�
        
        http://blog.csdn.net/pizi0475/article/details/6301792
    }
}



REF{
	��REF��sqlite �� http://www.cnblogs.com/cxjchen/p/3153553.html
	��REF��ATS wiki
	��REF��
	ATS�ܹ����http://blog.csdn.net/ljy1988123/article/details/50386458
	��REF��chunk encoding �ֿ鴫�����
	http://blog.csdn.net/xifeijian/article/details/42921827
	
	��REF�������Ƶ�URL��Ȩ
	https://help.aliyun.com/document_detail/45210.html?spm=5176.doc49567.6.552.U2K62Q
	��REF��m3u8 hls ts
	http://www.cnblogs.com/haibindev/archive/2013/01/30/2880764.html
	http://blog.csdn.net/langeldep/article/details/8603045
	
	��REF��squid �۵���Դ http://blog.chinaunix.net/uid-8474831-id-3830240.html
	
	ngx������Ⱥ
	http://www.2cto.com/os/201109/106387.html
	
	shell �ı�������
	http://blog.csdn.net/menlinshuangxi/article/details/7979504
	
	nginx if ��rewrite����
	https://xwsoul.com/posts/761
	
	�ű�֮�Ҹ������ֲ�
	http://shouce.jb51.net/perl/index.html
	
	������ ��Ϣ
	http://www.server110.com/system/
	
	�Կ���ַ�������ڴ��ַӳ��
		http://www.cnblogs.com/Wandererzj/archive/2012/04/23/2467127.html
	
	linux kernel{
		ջ�����Ĭ��/proc/sys/kernel/randomize_va_space 2
		http://www.2cto.com/os/201212/178306.html
		�ٷ���64λ���ڴ�
		https://www.kernel.org/doc/Documentation/x86/x86_64/mm.txt 
		2.6.32
		http://www.cnblogs.com/azenk/p/4674158.html
	}
	
	����
	http://blog.chinaunix.net/uid-23069658-id-3413957.html
	
	python js Node.js ����
	http://www.liaoxuefeng.com
	
	good blogs{
		��blog��ͬ��
		http://blog.chinaunix.net/uid/13746440/cid-211758-list-5.html
		��blog��ATS �ٷ�����
		https://blog.zymlinux.net/index.php/archives/756
		��blog��ͬ�У�������linux�������� http://blog.csdn.net/u010954257/article/details/54178144
		ATSʹ��
		http://blog.csdn.net/u010954257/article/details/54178145
		�Ա���TS��squid
		http://blog.chinaunix.net/uid-23242010-id-2973123.html
		CDN�����Ϣ
		http://www.dnsdizhi.com/
		���磬c,php,����ԭ���Ȥζ
		http://blog.csdn.net/21aspnet/article/details/6575705
		�㷨������
		http://blog.csdn.net/stpeace/article/details/38827671
		web/�ƶ���
		http://blog.csdn.net/mergerly/article/details/44306403
		ѩ�岩������
		http://blog.csdn.net/tao_627/article/details/44678225
		���̵������ܰ�
		http://blog.chinaunix.net/uid-23069658-id-3413957.html
	}
	
	hash
	http://kb.cnblogs.com/page/189480/
	
	Э��{
		����
		http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/0013868328689835ecd883d910145dfa8227b539725e5ed000
		-���⣺һ�δ���һ�� ����һ��������һС����
		http://blog.csdn.net/qq910894904/article/details/41699541
		
		Э�̺��첽 -Tim Shen�Ĵ�
		https://www.zhihu.com/question/32218874
		Э�̣�����������أ�ע������
		http://gashero.iteye.com/blog/442177
	}
	

	C++ IDE http://www.cnblogs.com/findumars/p/5797486.html
	eclipse http://blog.csdn.net/dugujiujian1124/article/details/46801823
	
	shell �ļ�����
	http://blog.chinaunix.net/uid-16728139-id-3415706.html
	
	Perl basics:
	http://blog.csdn.net/gexiaobaohelloworld/article/details/8931833
	Perl ����
	http://www.chinaunix.net/old_jh/25/159388.html
	nginx location ����
	http://blog.sina.com.cn/s/blog_97688f8e0100zws5.html
	
	TCP backlog ��accept����http://blog.csdn.net/russell_tao/article/details/9111769
	
	g++ 4.8 http://www.linuxidc.com/Linux/2015-01/112595.htm
	
	��̬�����⹤��{
		http://blog.csdn.net/jinhill/article/details/6673734
	}
	
	ѹ�����Թ���{
		
		ab,�̳�
		http://www.cnblogs.com/0201zcr/p/5045730.html
		
		�б�1
		http://www.oschina.net/news/30374/10-free-tools-to-loadstress-test-your-web?from=rss
	}
	
	ATS{
		ATS��Ҫ���ݣ�
		���á������Ӳ��cache(��COSS)��memcache(�����㷨CLFUS��LFRU?)�����߳�(������̼�أ�n+m+ �̷ֱ߳��Ӧ�����¼�����,Ӳ��IO,accept����־)
		������IO����Ӳ��IO����
		
		���Ϸ���{
			��Ⱥģ��ͼ�ط�������Ҫ��Ϊ��ģ�⻷�����ܹ����У�����������{
				docker??
				kvm
				xen?
				microwulf?����linux?
				vmware Team?
			}
			ѹ������ ���Ա�׼����Ҫ�������ܣ����ܼ�Ⱥ{}
			
			CDNԭ�����е�CDN�ܹ�������CDN����
			ע�룿
			4��7�����ԭ��
			nginx
			DNSԭ�� http://www.txrjy.com/forum.php?mod=viewthread&tid=916367
			�߲�������
			HTTPЭ��
			ATSԴ�����{
				https://github.com/oknet/atsinternals
				���߳�ԭ������IOģ��
				�߿��ú͸߲����ı�֤��ʽ
			}
			ATS���
			ATS������Ͳ������
			ATS��ά�����ԣ���� ����
			http://blog.csdn.net/tao_627/article/details/32718875
			web cacheԭ��
			IO�ٶȷ���{
				��Ϊ�ڴ�/Ӳ��
				�ڴ�ṹ�����hit���㷨
				����IO������ԭ��
				SSD
				RAID
			}
		}
		
		���Ž���{
			 �������ĵá�

			0��atsĿǰ�ĵ������Ǻ��٣�����������������Ľ��������ֻ�������е������϶��¹���

			1���࿴�ٷ��ĵ�

			2���࿴�����ļ������˵��

			3������ʵ�����

			4������Ҫ��ats�İ�װĿ¼�������ļ�Ŀ¼����־Ŀ¼�����Ŀ¼������Ŀ¼�����Ŀ¼Ū���

			5����ʹ�û����ĸ�������

			6���˽�������ʽ

			7���˽�http���֪ʶ���ر��Ǹ����������ص�����

			8�������ʼǣ���Ⱥ�ﾭ��������һЩ�Ƚ��м�ֵ�����ݣ��ȼ����������Ժ����

			9����Ҫʲô���ʣ��������ߡ�����������Լ����������϶��ܽ����

			�����ߡ�

			1��firebug�Ȼ����������ߵ�ʹ��

			2��curl�鿴��Ӧͷ��
		}
		
		ATSԴ�����
		https://github.com/oknet/atsinternals
		
		qqȺ�����Դ
		
		��ϵ{
			ѩ�岩������
			http://blog.csdn.net/tao_627/article/details/44678225
		}
		
		�����߳�ģ��{
			����+����
			http://www.cnblogs.com/liushaodong/archive/2013/02/26/2933280.html
			�̵߳��¼�����
			http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=13776576&id=5606097
		}
		
		
		���壬�ܹ�������˵ngx��ats������Э�̣���
		http://blog.csdn.net/ljy1988123/article/details/50386458
		
		ʹ���򣬲�����
		http://blog.linuxphp.org/archives/1641/
		
		many infos
		https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=2&tn=baiduhome_pg&wd=goaccess%20trafficserver&rsv_spt=1&oq=goaccess%2520ats&rsv_pq=aea4ab0800006a46&rsv_t=e6d0opyeSJEfrLSK0N0tmgptpQtH0YfcIqEmzFCxz5CV22oY%2FD6cd1m2JREjQvl7vXQV&rqlang=cn&rsv_enter=1&sug=goaccess&inputT=5384&rsv_sug3=29&rsv_sug1=14&rsv_sug7=100&rsv_sug2=0&rsv_sug4=6030
		
		���������ԭ��http://www.cnblogs.com/wangpenghui522/p/5498427.html
		
		����֪ʶhttp://www.zhangxinxu.com/wordpress/2013/05/caching-tutorial-for-web-authors-and-webmasters/
		
		2016.1.25 deep look into ATS
		https://www.bizety.com/2016/01/25/deep-look-into-apache-traffic-server/
		
		2016 ATS& CDN
		http://www.infoq.com/cn/presentations/apache-traffic-server-and-cdn-practice
		
		�ṹ���Խ���2016-2
		http://www.open-open.com/lib/view/open1455771560339.html
		
		2010��ʱ��Ӧ���������:http://blog.sina.com.cn/s/blog_502c8cc40100mw7n.html
		
		����1: https://sanwen8.cn/p/1b5GQep.html
		
		OFFICIAL
		https://docs.trafficserver.apache.org/en/latest/index.html
	}
	
	HTTP1.0/1.1����
	http://blog.csdn.net/shaobingj126/article/details/51392587
	
	RFC2616
	https://tools.ietf.org/html/rfc2616
	
	��Դ��gitbug,sourceforge,��Դ�й�
	
	automake http://blog.csdn.net/liang890319/article/details/8274917
	
	������Ӧ�ò㸺�ؾ��� http://blog.jobbole.com/74131/
	
	
	
	�Ƽ���/��·��ȫ/������� epoll/select/poll
	*http://www.cnblogs.com/Anker/p/3265058.html
	ngx{
		��REF��ngx types
		http://nginx.org/en/docs/http/ngx_http_core_module.html#types
	
		��REF��ngx rewrite
		http://blog.csdn.net/xiao_jun_0820/article/details/9397011
		
		32λ��8�ֽڶ����ԭ�򣺱�֤������ĵ�ַ���Ա���cast���κ����͵�ָ�������ʣ����mallocӦ�ò������align�����
		memalign valloc  http://blog.csdn.net/syc0616/article/details/3734941
		
		ngx slab pool: http://www.cnblogs.com/doop-ymc/p/3412572.html
		ngx �ڴ�ط��� http://www.cnblogs.com/doop-ymc/p/3418514.html
		
		nginx�¼�/�ڴ�
		http://www.cnblogs.com/fll369/archive/2012/11/29/2794939.html
			
		Nginx�̳̣�Nginx ������̸������ָ��ִ��˳��(ϸ��)
		*https://openresty.org/download/agentzh-nginx-tutorials-zhcn.html 

		*nginx API and developers' documentation
		*http://blog.csdn.net/lxzo123/article/details/6707054 �������HTTPЭ�飨ת�� 
		
		*Andrew :Chapter ��nginx�� in ��The Architecture of Open Source Applications��
		*The Architecture of Open Source Applications http://www.aosabook.org/en/index.html
		*NGINX ADMIN DOC https://www.nginx.com/resources/admin-guide/?_ga=1.52767648.966571952.1482822187
		Nginx���������ŵ���ͨ���� *http://tengine.taobao.org/book/chapter_05.html  
		nginxԴ����� 2011 *http://blog.csdn.net/livelylittlefish/article/category/838107  
		nginxԴ��ѧϰ��Դ 2012 *http://www.cnblogs.com/yjf512/archive/2012/06/13/2548515.html 
		
		module config *http://blog.csdn.net/poechant/article/details/7657955 
	}
}

easymistake{
	linux����ǽ http://www.myhack58.com/Article/48/66/2014/51687.htm
	need module points, should pass as address
}

shellcmd{
	tail awk
}

mail{
	sys@isurecloud.com zhaoziyi@isurecloud.com     xiaoguang@isurecloud.com
	{
		ѧϰ���ݣ�{
			��װNGINX���޸������ļ������м򵥵�HTTP���������ͼ򵥵�proxy������
			��NGINX�������źŲ���
			
			NGINX��ģ���ص㣬
			�����¼�����ʽ��
			select/poll/epoll����
			�˽���һЩ���ˮƽ��������Ե������Nagle�㷨���������
			
			ѧϰNGINX Admin Guide and Tutorial�ĵ������÷���
			Basic Functionality����{
				*Web server
				*Serving static content
			}
		}
		
		�������⣺{
			Nginx��config�ļ�д����õ�Perl��������ʽ��̫��Ϥ��
			X-Forwarded-For��
			geo ָ�����һ��
			geo $country {
				...
				proxy          2001:0db8::/32; #�������˼ IPV6��Ϊʲôֻ��64λ����XFF�й���
			}
			
		}
		����ƻ���{
			Nginx��������Ļ�������
			
			ѧϰNGINX Admin Guide and Tutorial�ĵ�
			Basic Functionality ����{
				Reverse proxy 
				Compression and decompression
				Web content cache
			}
			Load Balancing ����{
				HTTP load balancer
				TCP and UDP load balancer
				Using the PROXY protocol
			}
			
			
		}
	}
}

thoughts{
    �Լ���һ�����̶߳ϵ��������ع���
    
    �ö���ؼ��ֿ������ıʼ�ϵͳ{
        ��������ѷ�����
        ������linux ����
        ����������
        �ȵȵȵ�
    }
    
    ��upwork���Կ����Ŷӣ������ҵ���{
        - �ȶ����У�ϣǿ�����硢����
        - ���ȶ��ģ����������š��ܸ硢����
    }
    
    ץ�⼦�����ֲ�ʽ������Ⱥ
    
    python dict��ʵ��
    
    �����Զ������ı��޸��Զ���
    
    - how to become freelancer see֪��
    - X windows server

    - vim script
    - JS, DOM and webdev see֪��
    ginx conf�����ı��༭��
    print x bit HEX �� to git
    ����ֱ����ͼ��Ŀ�������
    
    asyncio, �첽��asynclib?
	����push��pop�̰߳�ȫ��list
	[website]���ֿɿ������ݼ�¼ ���ƣ����ڣ����������Ŷ�
	[tool] ������׶κ�ʱ��⹤��
	��code���������ȼ�¼��
	��TOOL��boost lib
	�����ڲ������ӳ١���Ϸ��������ͨ��ʵ��
	������Э��coroutine������ͨ�������õ������ǣ��Ӻ�����������ʱ���أ������л���
	��shellcode��http://www.zixijiaoshi.com/html/server/Linux/2014/1225/13844.html
	http://blog.csdn.net/mikayong/article/details/52057818
	��thought��libeventcode
	��thought��
	��д״̬��
	��thought��grafana���Զ�������ݿ��ӻ�
	��Q��websocket ȫ˫��ͨ�� ������ʺ�����ҳ�κ���ҳ��ʱ����
	ԭ��
	http://www.cnblogs.com/purpleraintear/p/6158104.html
	
	��thought��
	GO R lang
	��thought��:�����ռ��Զ��򿪣���������ҳ��ť�����ڸ�����ҳ
	��thought������ѹ��
	
	��һ��������cookie�ķ�����������
	git�ϣ��ύATS��˵������
	
	gitѧϰ����򹫿���Ŀ����
	
	�о��Լ��ر�ϲ��ģ�⣺ ģ��-��ģ-�������
	�������������-����ѹ�֣��������죻
	����ұ�֤���������ƺ����档
	��ͨ�谭������̽����
	1.�����Ӧ��Ϊ���ҷ����������ߡ�
	2.�˽��Լ������Լ���̽������
	
	��paper?
	
	�һ��jenkins���������
	tcдһЩģ���ض������ͨ��˫���Ľű�
	
	һ����ҳ��������ͼ���ͻ�������Ϸʱ����
	�����������棿����ô����ȡ���п���������IP�أ�
	��Դ�������
	
	���绷���ſ�ͼ �����̣��û����ڿͣ��м��̣�˽��������
	
	������ͼ�ʼ�
	
	�Զ��������
	
	�����ٶ����ţ����ڲ���ʵ��
	
	��·������� - ���Ӽ�(���Ӽ�) - �ݵĵ�����ͬ2~n�����������
	
	����ϵͳѧϰ��ϵ��ѧϰ��վ
	
	�ز���ʽ����˿ںľ����⣿
	������rewrite����ģ������Ϊhttp handler������
	method:�Ķ�������{�Ķ��ٶ�����ٶȣ�ͬ��ѧϰ������}
	����+���� ���﷨ ʵ��С����{
		����+����
		"����"+����+����
		������
		����+���ݴ�׼ȷ����: ȡ 20�� ��ͬ�� XXX ��վ
	}
	
	lz4������Ŀǰ�����ڴ�ѹ���㷨����xmemcpy&memcpy&strcpy
	���ݼ����ӻ�����
	�ٶ��Ʋ�Ʒ
	https://cloud.baidu.com/product/bml.html
	��Դ�����
	ά��������linkedin
	math & physics & opensource work
}

��{
	������Linux�ں˼ܹ���
}

�ܽ�{
	���ܽ᡿�����ܽ��ʱ�������ݵ����У��������QA�����ϣ�ϵͳ����ϵ��ͼ�����뷨�������е�ʱ���һ������ҲҪС��һ��
}

tool{
	��tool��
	����ͼ���� edraw
	http://www.360doc.com/content/13/1024/22/9200790_323876899.shtml
	https://www.processon.com/
	Xmind˼ά��ͼ����
}

standard{
	[?]������Ǵ����в����׵ĵط�[!]�����Ҫ�ĵط�
}