//
// Created by Akeena on 5/1/2024.
//

#include "ReservationManager.h"

ReservationManager::~ReservationManager() {

}

ReservationManager::ReservationManager() {
    db = new ReservationDB();

}

ReservationManager::ReservationManager(ReservationDB *db) : db(db){}

/**
 * Creates a new reservation and inserts it into the database.
 *
 * @param napSpotID The ID of the nap spot for which the reservation is made.
 * @param userId The ID of the user making the reservation.
 * @param userName The name of the user making the reservation.
 * @param startTime The start time of the reservation.
 * @param endTime The end time of the reservation.
 * @param status The status of the reservation.
 */
void ReservationManager::create_reservation(int napSpotID, int userId, std::string userName,std::time_t startTime, std::time_t endTime,
                                            std::string status) {
    Reservations newReservation(napSpotID,userId,startTime,endTime,status);
    db->insert_reservation(napSpotID,userId,userName,startTime,endTime,status);
}

/**Cancels the reservation associated with the specified reservation ID.
 *
 * @param reservation_id The ID of the reservation to cancel.
 */
void ReservationManager::cancel_reservation(int reservation_id) {
    db->deleteReservation(reservation_id);
}
/** Modifies the start time of the reservation identified by the specified reservation ID.
 *
 * @param reservation_id The ID of the reservation to modify.
 * @param newStartTime The new start time for the reservation.
 */
void ReservationManager::modifyStartTime(int reservation_id, std::time_t newStartTime) {
    // Call the database method to modify the start time of the reservation
    db->modifyStartTime(reservation_id, newStartTime);
}


/**Modifies the end time of the reservation identified by the specified reservation ID.
 *
 * @param reservation_id The ID of the reservation to modify.
 * @param newEndTime The new end time for the reservation.
 */
void ReservationManager::modifyEndTime(int reservation_id, std::time_t newEndTime) {
    // Call the database method to modify the end time of the reservation
    db->modifyEndTime(reservation_id, newEndTime);
}

/**Modifies the status of the reservation identified by the specified reservation ID.
 *
 * @param reservation_id The ID of the reservation to modify.
 * @param newStatus The new status for the reservation.
 */
void ReservationManager::modifyStatus(int reservation_id,  std::string newStatus) {
    // Call the database method to modify the status of the reservation
    db->modifyStatus(reservation_id, newStatus);
}

/**Retrieves the nap spot ID associated with the reservation identified by the specified reservation ID.
 *
 * @param reservation_id The ID of the reservation.
 * @return The nap spot ID associated with the reservation.
 */
int ReservationManager::get_napSpot(int reservation_id) {
    return db->fetch_napSpotID(reservation_id);
}

/**
 * @brief Checks the availability of a nap spot for a given time range.
 *
 * This method checks whether a nap spot is available for reservation within the specified time range.
 * It queries the existing reservations for the specified nap spot and compares their time ranges
 * with the input start and end times to determine if there are any conflicts.
 *
 * @param napSpotID The ID of the nap spot to check availability for.
 * @param startTime The start time of the desired reservation.
 * @param endTime The end time of the desired reservation.
 * @return true if the spot is available for reservation within the given time range, false otherwise.
 */
bool ReservationManager::check_availability(int napSpotID, std::time_t startTime, std::time_t endTime) {
    // Fetch existing reservations for the specified nap spot within the given time range
    std::vector<Reservations> reservations = db->getReservationsForNapSpot(napSpotID);

    // Iterate through existing reservations to check for conflicts
    for (Reservations reservation: reservations) {
        // Check if the reservation overlaps with the specified time range
        if ((reservation.getStartTime() <= startTime && reservation.getEndTime() > startTime) ||
            (reservation.getStartTime() < endTime && reservation.getEndTime() >= endTime) ||
            (reservation.getStartTime() >= startTime && reservation.getEndTime() <= endTime)) {
            // Reservation overlaps with the specified time range, so the spot is not available
            return false;
        }
    }
    // no conflicting reservations with the queried time
    return true;
}






