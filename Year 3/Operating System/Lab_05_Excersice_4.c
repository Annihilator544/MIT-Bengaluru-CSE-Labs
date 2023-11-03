Semaphore Customers = 0;
Semaphore Barber = 0;
Mutex Seats = 1;
int FreeSeats = N;

Barber {
	while(true) {
			/* waits for a customer (sleeps). */
			down(Customers);

			/* mutex to protect the number of available seats.*/
			down(Seats);

			/* a chair gets free.*/
			FreeSeats++;
			
			/* bring customer for haircut.*/
			up(Barber);
			
			/* release the mutex on the chair.*/
			up(Seats);
			/* barber is cutting hair.*/
	}
}

Customer {
	while(true) {
			/* protects seats so only 1 customer tries to sit
			in a chair if that's the case.*/
			down(Seats); //This line should not be here.
			if(FreeSeats > 0) {
				
				/* sitting down.*/
				FreeSeats--;
				
				/* notify the barber. */
				up(Customers);
				
				/* release the lock */
				up(Seats);
				
				/* wait in the waiting room if barber is busy. */
				down(Barber);
				// customer is having hair cut
			} else {
				/* release the lock */
				up(Seats);
				// customer leaves
			}
	}
}
