def solution(enroll, referral, seller, amount):
    answer = [0] * len(enroll)
    name_to_idx = {name: i for i, name in enumerate(enroll)}
    
    for i in range(len(seller)):
        employee = seller[i]
        profit = amount[i] * 100
        
        referee_idx = name_to_idx[employee]
        referrer = referral[referee_idx]

        while referrer != "-" and profit >= 10:
            incentive = profit // 10
            answer[referee_idx] += profit - incentive

            profit = incentive
            referee_idx = name_to_idx[referrer]
            referrer = referral[referee_idx]
        
        incentive = profit // 10
        answer[referee_idx] += profit - incentive

    return answer