#PS: I couldve used  REGEX, but im really trying to do everything with no additional modules

#Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. For example:
#
#domain_name("http://github.com/carbonfive/raygun") == "github" 
#domain_name("http://www.zombie-bites.com") == "zombie-bites"
#domain_name("https://www.cnet.com") == "cnet"

def domain_name(url):
    list = ['https','http','www.', '://']
    domain = ''
    for x in list:
        if x in url:
            url = url.replace(x, '')
            
    for i in url:
        if i != '.':
            domain += i
        else:break


    return domain

if __name__ == '__main__':
    print(domain_name("http://google.com"))
    print(domain_name("http://google.co.jp"))
    print(domain_name("www.xakep.ru"))
    print(domain_name("https://youtube.com"))