### BASICS => ![alt text](image.png)

```` 7 stargies => ALGO ```

1. Round Robin => most popular and most simpler 

![alt text](image-1.png)

>is order me bhejega 

1 -> 2 -> 3 -> REPEAT [in-terms-of-server]

![alt text](image-2.png)

- if a ll server have same capabilty then use this 

2. Least Connentions

![alt text](image-3.png)

send the new req to least connection contating server

![alt text](image-4.png)

> helpful when you have seasion of valuable length meaning one session can last 10 min and the other can last 1 min ![alt text](image-5.png)

3. Least Response Time 

- based on responsives => first it will try the lowest response time and fewest active connection 

![alt text](image-6.png)

![alt text](image-7.png)

so basically manlo pehle ye 30 resp high me then 20 med then 10 low me until it redirects them to back the third server 

> helpful when you need to provide fast reponsive time and server have diff capabilties 

4. IP hash => based on client's IP address

> useful when you want your client to connect to the same server continuosly 

![alt text](image-8.png)

now if client1 send a req lb will hash it's ip and lets say it will send it to 2nd server now the client will get the req to 2nd server 

- if 2nd server have some info about your client then this algo is a good choice 