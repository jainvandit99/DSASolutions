from bs4 import BeautifulSoup
from selenium import webdriver
import sys
from newCodeGenerator import save, request_user_input
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

locator = (By.CLASS_NAME , 'question-content__JfgR')


options = webdriver.ChromeOptions()
options.add_argument('--ignore-certificate-errors')
options.add_argument('--incognito')
options.add_argument('--headless')
driver = webdriver.Chrome("/usr/local/bin/chromedriver", chrome_options=options)


def updateReadme(codeName,formattedCodeName,data):
    save(''.join(['# ',codeName,'\n',str(data)]),formattedCodeName + '/readme.md')

def main():
    percentFormattedCodeName = sys.argv[2]
    codeName = percentFormattedCodeName.replace('%20',' ')
    formattedCodeName = sys.argv[1]
    print('leetcode!')
    url = request_user_input('Enter the leetcode URL')
    driver.get(url)
    driver.implicitly_wait(10)
    page_source = driver.page_source
    soup = BeautifulSoup(page_source,'html.parser')
    results = soup.find_all('div', class_='question-content__JfgR')
    data = results[0].find('div', attrs={})
    print(data)
    updateReadme(codeName,formattedCodeName,data)

if __name__ == '__main__':
    main()