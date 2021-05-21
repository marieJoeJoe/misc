#lang racket
(define (fact x)
 (cond [(> x 0) (* x (fact (sub1 x)))]
[else 1]))
(fact 10)
;;(+ 7 8)
(string? "hello")
(equal? 42 "bar")
(expt 3 2)
(+ 1 2 3 4)
;;(tpye fact)
;;(fact "helloworld")
