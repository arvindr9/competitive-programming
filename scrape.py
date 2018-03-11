from bs4 import BeautifulSoup
import os
import urllib
import http
handle = input("Type your handle")

for i in range(1,63):
	print('grabbing data')
	gen_url = 'http://codeforces.com/submissions/'+handle+'/page/' + str(i)
	print(gen_url)
	r = urllib.request.urlopen(gen_url).read()
	print('done')

	problem_id = []
	no_name = []

	soup = BeautifulSoup(r, "html5lib")
	co = soup.find_all('td')

	for row in range(1,len(co)):
		if len(co[row].attrs) == 4:
			if len(co[row].span.attrs) == 5:
				if co[row].span.attrs['submissionverdict'] == 'OK':
					problem_id.append(co[row].span.attrs['submissionid'])
					no_name.append(row)

	contest_id = []
	for j in range(0,len(no_name)):
		query = no_name[j]
		contest_id.append(co[query-2].a.attrs['href'].split('/')[3])

for j in range(0, len(contest_id)):
    url = 'http://codeforces.com/contest/'+contest_id[j]+'/submission/'+problem_id[j]
    r = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(r, "html5lib")
    var = soup.find_all('td')
    try:
        problem_name = var[2].a['href'].split('/')[4]
        print('getting code '+contest_id[j]+'-'+problem_name)
        co = soup.find_all('div')
        target = open(contest_id[j]+'-'+problem_name, "w")
        for row in co[26].find_all('pre',attrs={"class" : "program-source"}):
            target.write(row.text)
        print('got code '+contest_id[j]+'-'+problem_name)
        target.close()
    except TypeError:
        print('error')
        pass