import smtplib

fromaddr = 'hellobheri@gmail.com'
toaddrs  = 'hellobheri@gmail.com'
msg = 'There was a terrible error that occured and I wanted you to know!'


# Credentials (if needed)
username = 'hellobheri@gmail.com'
password = 'sri@1991'

# The actual mail send
server = smtplib.SMTP('smtp.gmail.com:587')
server.starttls()
server.login(username,password)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()
