# how do we apply horizontal scaling

![alt text](image-2.png) => if we have single server 

![alt text](image-3.png) => but now we have diffrent server's how do we apply now ![alt text](image-4.png) which server should it go 

> look closely in the photo we can add something which can redirect the req : loadbalancer[used-to-disturbute-traffic] 

![alt text](image-5.png)

> whenever a new req comes the load balancer it see where's the least lad give thier , and it also control the fault tolerance , meaning if ![alt text](image-6.png) serv 3 die cut the connection and send traffic to server 1 and 2 untill 3 is available 

> one more advatage make more scalable add server load balancer will ![alt text](image-7.png) just evenly distubute

## SUMMARY

![alt text](image-8.png)