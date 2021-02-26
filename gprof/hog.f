      program hog
      implicit none
      logical*4 lloop
      integer*4 i, j
      real*4 x
      lloop = .true.
      x = 3.14/2.
      i = 0
      j = 0
      do while (lloop)
        x = sin(x)
        if (x .lt. .01) x = 3.14/2.
        i = i+1
        if (i.eq.10000000) then
          j=j+1
          write (6,*) ' hog: i,j=',i,j
          i=0
        end if
        if (j .eq. 100) lloop = .false.
      end do
      end
