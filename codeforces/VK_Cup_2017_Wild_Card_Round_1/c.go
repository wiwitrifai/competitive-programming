package main 

import "fmt"

func main() {
  var n int
  fmt.Scan(&n)
  var ans [100003]int
  m := 0

  for n >= 2 {
    if n >= 2 {
      ans[m] = 1
      m++
      n = n-2
    }
  }
  if n > 0 {
    ans[m-1] = 7
  }
  for m > 0 {
    m--
    fmt.Print(ans[m])
  }
  fmt.Println()
}