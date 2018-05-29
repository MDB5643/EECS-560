Input output specifications:
============================

### Input file 

#### specification

Line 0: number of applications to be scheduled (`appCount`)
for 3*appCount number of lines in bunch of 3 lines i-th time stamp:
- `<Time Stamp>`
- `<Number of tasks to be scheduled (popped out of the schedule queue)>`
- `<Application to be added to scheduler>`
  - format: `<AppId> <App Name> <Task> <Task> ... <Task>`

Task format: `(<tid>, <nice>, <appId>, <ttl>)`

#### Example
```
5
T0
0
1 init (0, 0, 1, 5) (1, 5, 1, 7) (2, 2, 1, 2) (3, 1, 1, 1)
T1
3
2 App1 (4, 0, 1, 5) (4, 5, 1, 7) (5, 2, 1, 2) (6, 1, 1, 1) (30, 2, 1, 2) (6, 1, 1, 1)
T2
5
3 App2 (7, 0, 1, 5) (8, 5, 1, 7) (9, 2, 1, 2) (10, 1, 1, 1) (9, 2, 1, 2) (10, 1, 1, 1)
T3
2
3 App3 (7, 0, 1, 5) (8, 5, 1, 7) (9, 2, 1, 2) (10, 1, 1, 1) (9, 2, 1, 2) (10, 1, 1, 1)
T4
10
3 App4 (7, 0, 1, 5) (8, 5, 1, 7) (9, 2, 1, 2) (10, 1, 1, 1) (9, 2, 1, 2) (10, 1, 1, 1)
```
### Output file 

#### specification
for `appCount` number of times
- `<Time stamp>`
- `Tasks executed: <tid>(<appid>, <nice>) <tid>(<appid>, <nice>) ... <tid>(<appid>, <nice>)`
- `Application added to queue: <app name>`


#### Example
```
T0
Tasks executed:
Application added to queue: init

T1
Tasks executed: 0(0) 2(0) 3(0)
Application added to Queue: App1

T2
Tasks executed:
Application added to Queue: App2

T3
Tasks executed:
Application added to Queue: App3

T4
Tasks executed:
Application added to Queue: App4

T5
Tasks executed:

Done.

```
