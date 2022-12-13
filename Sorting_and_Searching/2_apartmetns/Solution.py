# f = open("Sample.txt")
# input = lambda : f.readline().strip()


n,m,k = map(int,input().split())

applicants = list(map(int,input().split()))
apartments = list(map(int,input().split()))

applicants.sort()
apartments.sort()


i = 0

j = 0


check = lambda i,j: abs(applicants[i]-apartments[j]) <=k

matched = 0
while (i<n and j < m):
    #we try to give the smallest apartment to the applicant that needs the smallest so far
    if(check(i,j)):
        matched += 1
        i+=1
        j+=1

    else:
        if(applicants[i] < apartments[j]):
            i += 1
        elif(applicants[i] > apartments[j]):
            j+=1
    
print(matched)