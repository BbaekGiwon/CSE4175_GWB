# ch.11

2024/05/28

## p.3

주소가 두개다

ip address(logical): 

mac address(physical): 

ip header에 적힌 도착지 ip address는 physicla layer에서 그냥 data임

data link layer에서는 physical 주소가 사용된다. 따라서 ip와 mac이 mapped 되어야 한다.

## p.4

### ARP

물리적 주소를 모르는 경우 물리적주소 물어봄(Broadcast ARP)

Link Layer protocol로 간주

## p.6

physical 모르니까 0으로 채움 -> request의 경우

## p.7

ethernet / ip

## p.8

hardware length: 6byte

operation: arp request인지 reply인지

ARP는 한번 보내면 받는 놈이 table에 써놓는다. 그래서 빈도가 적다. 그래서 대충 byte 할당 함 + packet이 너무 작으면 안됨

## p.9

arp 내용은 data link frame에 data부분에 들어간다

## p.5

request: ip주소 이거이신분?

reply: 그거 나임, physical 주소는 이거고



unicast: 특정 하나, wifi라고 치면 내꺼 아니면 안받음

broadcast: 모두(TTL로 범위조절 가능)

multicast: 특정사용자 그룹, 스트리밍에 사용

anycast: 여러명 중에 아무나 받아라

## p.12

대충 물리적 주소 reply로 보낸다

## p.15

### DHCP

IP address 자동으로 할당 -> 효율적인 관리가 가능하다

## p.19

## ICMP

ip는 보장안해준다. 손실이 돼도 알빠노

그래서 ip 냅두고 ICMP한개 더 만듬

## p.21

꼭 패킷손실이 아니더라도 현상황등의 정보를 뽑기위해 ICMP활용

## p.22

ping: ICMP echo 전송, 보내서 살아있는지 확인 가능

tracerrt: 목적지까지 가는데 중간의 router도 출력







2024/05/30

## p.22

5개의 error reporting -> 문제 생기면 source쪽으로 메세지 보내줌

## p.23

destination unreachable: 끝타리 갔더니 갈곳이 없음

source quench: buffer가 꽉차면 router가 못 받음(drop)

Time exceeded: TTL이 0이 되는 경우

Parameter problem: header가 잘못됨

redirection: R1한데 보내보니까 R2가 나은것 같은경우, 다음부터 R2로 보내라고 메세지, drop은 아님(p.25)

## p.26

ICMP가 drop 될수도 있음 -> 그렇다고 또 ICMP를 만들지는 않음

여러개가 문제면 첫번째 fragment만 생성

## p.27

### ICMP query

error가 아니라 상태 표현해주는 것, type으로 표현함 -> 누군가가 필요해서 답해주는 거라 request, reply가 있음

## p.28

ping: echo rq&rp -> available

time stamp rq&rp: 목적지까지의 왕복시간

Address-mask: mask 알고 싶을 때

advertisement: 나 광고

## p.30

### debugging

ping: timestamp대체 가능, ping돌아오는 시간 측정하면 됨, available 한지

## p.33

tracerout: 경로를 알고 싶을 때, 시간, ip

3번씩 보냄 - 시간 균등하게 보냄

ttl을 계속 키워가면서 출력함 -> 마지막에 도착했는데 ttl==0 이면 오류X -> 근데 listen 상태가 아님 -> drop -> unreachable 옴 -> 마지막 도착지 정보 출력

## p.40

### NAT

ip 주소가 부족함 -> private ip -> 이쪽은 uniuqe ip가 아니다

## p.36

DHCP: 공유기가 자신에게 연결된 통신기기에 local ip주소를 준다 -> 나갈때는 외부 ip로 바뀌어서 나감

## p.39

외부에서 공유기로 들어왔을때 어디로 가야함? -> port

Destination = 80 이거 걍 정한거임

Source = 

대충 router가 외부아이피 + 포트로 들어오면 내부에 연결된 서버로 접속해줌

portforwarding: 포트 - 내부 아이피 연결