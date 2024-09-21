# ch.12

2024/05/30

## p.2

### Scheduling

그래서 router가 어떤 순서로 보내는가?

## p.3

### FIFO

flow not distinguished

no congestion control(속도조절 X)

tail drop

fair in temrs of delay(온대로 보내므로)

bandwith not considered



priority를 부여하지 못한다

한놈이 10, 한놈이 1개 씩 보낼때, 1개씩 보내는 애는 10개나 기다려야함

## p.7

### Round Robin

flow 별로 queue를 둔다

processing 할때 queue당 하나씩 보낸다

그러면 나는 큰거 하나 보내면 되지롱~

## p.5

### Priority Queue

class 마다 queue

high priority가 다 보낸뒤에 low priority를 전송한다

고로 low priority는 평생 기다릴 수도 -> starvation

## p.8

### Fair queuing

우선순위 필요-> but 무조건적인 우선순위 X -> 적당히 low priority를 보내야한다

flow 3개 -> 점수를 매겨서 점수가 낮은놈 부터 보낸다 -> 큰거 하나 보낸 애는 좀 많이 기다리도록



weighted fair queuing은 가중치를 둬서 더 중요한 애는 점수가 적게 오르도록







2024/06/04

## p.10

안보내다가 보낼라고하면 -> 니가 안보낸거아님? 우선순위 안줌 ㅅㄱ -> 근데 매우 오랫동안 안보내다 보낼라하면 제일 작은 점수를 줌 -> 오랫동안의 기준은 정하기 나름

## p.13

weighted fair queuing: starvation 해결 가능

## p.14

weight가 같다면 ? (6) -> (1) -> (7) -> (11) -> 이런식으로 걍 작은대로

W A,B,C: 4,1,2 -> (1) ->(6) -> (2) -> (11) ...



## p.15

### Traffic shaping

왕창 들어오다, 안오다 (Bursty data) -> 일정하게 바꾸기

## p.16

Token bucket filter: bucket 안으로 누적됨, 꽉차면 더 안들어옴 일정한 속도로 참

token은 비용 -> 다쓰면 데이터 못받음 ㅇㅇ -> 1 tick당 토큰 하나씩 추가

## p.18

문제에서는 토큰이 꽉차있는 경우를 가정

## p.21

r -> bucket이 15kbps로 차고 있다.

10~30: 40kbps * 20 ms  - 15kbps * 20 ms = 500 bits

30~40: (50-15)kbps * 10 ms = 350 bits

40~60: (10-15)kbps * 20 ms = -100 bits

60~100: (20-15)kbps * 40 ms = 200 bits

bucket 크기가 950은 필요하다

## p.23

bucket 사이즈 고려

찾아보자.
