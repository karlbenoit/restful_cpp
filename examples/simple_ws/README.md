# simple_ws #

## fcgi flavor  ##
```
cp simple_ws.nginx /etc/nginx/sites-available
ln -s /etc/nginx/sites-available/simple_ws.nginx /etc/nginx/sites-enabled/simple_ws.nginx
nginx -s reload

spawn-fcgi -a 127.0.0.1 -n -f ./simple_ws_fcgi -p 9091
```

## standalone http flavor ##
```
./simple_ws_http --docroot . --http-address 0.0.0.0 --http-port 9090
```
