import smtplib

fromaddr = input("your address")
password = input('your password')
toaddrs  = input("recipient address ")
SUBJECT=input("ENTER SUBJECT")
TEXT = input("your message")

msg = 'Subject: {}\n\n{}'.format(SUBJECT, TEXT)
server = smtplib.SMTP('smtp.gmail.com:587')
server.ehlo()
server.starttls()
server.login(fromaddr,password)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()