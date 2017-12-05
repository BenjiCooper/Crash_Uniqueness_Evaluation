# !/usr/bin/ruby

# There's probably a Python library for this...
# Alas ... here's my attempt

require 'set'

def measure(s1, s2)
	tp = (s1 & s2).length
	fp = (s1 - s2).length
	fn = (s2 - s1).length
	return tp*fp + tp*fn
end

def dist(set1, set2)
	acc = 0
	set1.each do |s1|
		set2.each do |s2|
			acc = acc + measure(s1, s2)
		end
	end
	return acc
end

gt = Set.new [ (Set.new ['a', 'b']) , (Set.new ['c', 'd'])]
out1 = Set.new [ (Set.new ['a', 'b', 'c', 'd'])]
out2 = Set.new [ (Set.new ['a']) , (Set.new ['b']) , (Set.new ['c']), (Set.new ['d'])]
out3 = Set.new [ (Set.new ['a', 'b', 'c']) , (Set.new ['d'])]
out4 = Set.new [ (Set.new ['a', 'b']) , (Set.new ['c']), (Set.new ['d'])]
out5 = Set.new [ (Set.new ['a', 'd']) , (Set.new ['c', 'b'])]

oputs '(a) (b) (c) (d): ' + dist(gt, out2).to_s
puts '(a b c) (d): ' + dist(gt, out3).to_s
puts '(a b) (c) (d): ' + dist(gt, out4).to_s
puts '(a d) (c b): ' + dist(gt, out5).to_s
puts '(a b) (c d): ' + dist(gt, gt).to_s
