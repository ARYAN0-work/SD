## REQ FLOW [we have some user which are trying to acess our api on user our server]


                                                                                       app.demo.com
                                                                                        ----------> // after accessing the domain dns gonna send
                                                                                                       ip address and this ip adress is our server's so now they have where they are trying to send the req
WEB SERVER / MOBILE APP [we are using this things to access server]                                                          DNS 
                                                                                        <-----------                 172.16.254.254         
    / \   |  [when it gets the ip adress the server sends ip adress which ask for-data]                                                         
     |    |                                                                                        
     |    | 
     |   \ / [ after sending data tthe servers a html page or json response]

                                                                                    ------>WEB app 
                                                                                    |
[here we have our seerver , have neccary files to server browser and endpoints]Server ----> DB
                                                                                    |
                                                                                    --------> Cache 

[hostd on this IP adress our user dont have access to this intilly]                 172.16.254.254   
        |
        |
        |
        |
        \/

// they have access to domain ex:- app.demo.com then if they enter url they 
// will access to Domain name system[ system which maps to domain to the ip address] --it basically do this -->   app.demo.com    | 172.16.254.354
                                                                                                                   ...           |     ...