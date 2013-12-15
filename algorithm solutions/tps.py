from collections import deque

def tweets_per_second(tps, k):
  last_k = deque()
  for i in xrange(len(tps)):
  	if len(last_k) > 0 and i - last_k[0] >= k: # passed k
  		last_k.popleft()
  	while len(last_k) > 0 and tps[last_k[-1]] <= tps[i]:
  		last_k.pop()
  	last_k.append(i)
  	print tps[last_k[0]]

tweets_per_second([6, 9, 4, 7, 4, 1], 3)