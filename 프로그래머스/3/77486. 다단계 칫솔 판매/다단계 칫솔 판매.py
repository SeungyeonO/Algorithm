def solution(enroll, referral, seller, amount):
    PRICE_OF_TOOTHBRUSH = 100
    ANCESTOR_PROFIT_RATIO = 0.1

    answer = []
    parent_dict = dict(zip(enroll, referral))
    profit_dict = {key: 0 for key in enroll}
    
    for i, sell_amount in enumerate(amount):
        current = seller[i]
        parent = parent_dict[current]

        total_profit = sell_amount * PRICE_OF_TOOTHBRUSH 
        ancestor_profit = int(total_profit * ANCESTOR_PROFIT_RATIO)
        own_profit = total_profit - ancestor_profit

        profit_dict[current] += own_profit

        while parent != "-" and ancestor_profit >= 1:
            total_profit = ancestor_profit
            ancestor_profit = int(total_profit * ANCESTOR_PROFIT_RATIO)
            own_profit = total_profit - ancestor_profit
            
            current, parent = parent_dict[current], parent_dict[parent]
            
            profit_dict[current] += own_profit
    
    answer = list(profit_dict.values())

    return answer
