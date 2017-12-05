import itertools as it

def f_measure(truth, guess, beta=1.0):
    tp = fp = fn = 0

    t_map = create_mapping(truth)
    g_map = create_mapping(guess)

    g_collapsed = set().union(*guess) # g_collapsed = guess[0] U guess[1] U ... U guess[n]
    
    for a,b in it.combinations(g_collapsed, 2):
        truth_a = t_map[a]
        truth_b = t_map[b]
        guess_a = g_map[a]
        guess_b = g_map[b]
        
        if truth_a==truth_b:
            if guess_a==guess_b:
                tp += 1
            else:
                fn += 1
        elif guess_a==guess_b:
            fp += 1
        # True negatives not used

    precision = float(tp)/(tp+fp)
    recall = float(tp)/(tp+fn)

    return (beta**2 + 1)*precision*recall/((beta**2)*precision+recall)


def create_mapping(s):
    s_collapsed = set().union(*s)

    mapping = {}

    for ele in s_collapsed:
        set_of_ele = None
        for x in s:
            if ele in x:
                set_of_ele = x
                break
        mapping[ele] = x

    return mapping

truth = frozenset([frozenset([1, 2]) , frozenset([3, 4])])
out1 = frozenset([frozenset([1, 2, 3, 4])])
print f_measure(truth, out1, 10)
