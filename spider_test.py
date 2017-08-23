# -*- coding: utf-8 -*-
# @Author: Haut-Stone
# @Date:   2017-08-23 15:32:50
# @Last Modified by:   Haut-Stone
# @Last Modified time: 2017-08-23 16:21:40
import requests
import time

def get_http_text(url):
	try:
		r = requests.get(url, timeout = 30)
		r.raise_for_status()
		r.encoding = r.apparent_encoding
		return r.text[:1000]
	except:
		return 'op! something wrong with the network!'

def main():
	url = 'https://item.jd.com/12017634082.html'
	start_time = time.time()
	print('begin')
	for i in range(0, 5):
		text = get_http_text(url)
		if text == 'op! something wrong with the network!':
			print('第%d次抓取被发现了' % i)
		else:
			print('第%d次抓取成功了！' % i)
			print(text)

	end_time = time.time()
	all_time = end_time - start_time
	print('end :: 总用时 %d s' % all_time)
	exit()

if __name__ == '__main__':
	main()
