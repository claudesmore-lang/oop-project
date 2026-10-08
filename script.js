var reservations = [];
var occupiedRooms = [];

function reserveRoom()
{
    var customerName = document.getElementById("customerName").value;

    var roomNumber = parseInt(
        document.getElementById("roomNumber").value
    );

    var days = parseInt(
        document.getElementById("days").value
    );

    // Check maximum 5 records
    if(reservations.length >= 5)
    {
        alert("Maximum 5 records can be stored.");
        return;
    }

    // Check customer name
    if(customerName == "")
    {
        alert("Please enter customer name.");
        return;
    }

    // Check number of days
    if(isNaN(days) || days <= 0)
    {
        alert("Please enter a valid number of days.");
        return;
    }

    // Check whether room is already reserved
    if(occupiedRooms.includes(roomNumber))
    {
        alert("This room is already reserved.");
        return;
    }

    // Create reservation
    var reservation =
    {
        name: customerName,
        room: roomNumber,
        days: days
    };

    reservations.push(reservation);

    occupiedRooms.push(roomNumber);

    alert("Room reserved successfully!");

    // Clear input fields
    document.getElementById("customerName").value = "";
    document.getElementById("days").value = "";

    updateInformation();

    displayReservations();

    showEmptyRooms();
}


function updateInformation()
{
    var reserved = occupiedRooms.length;

    var empty = 10 - reserved;

    document.getElementById("reservedRooms").innerHTML = reserved;

    document.getElementById("emptyRooms").innerHTML = empty;

    document.getElementById("recordCount").innerHTML =
        reservations.length + " / 5";
}


function showEmptyRooms()
{
    var emptyRooms = [];

    for(var i = 1; i <= 10; i++)
    {
        if(!occupiedRooms.includes(i))
        {
            emptyRooms.push(i);
        }
    }

    if(emptyRooms.length == 0)
    {
        document.getElementById("emptyRoomList").innerHTML =
            "No empty rooms available.";
    }
    else
    {
        document.getElementById("emptyRoomList").innerHTML =
            "Empty Rooms: " + emptyRooms.join(", ");
    }
}


function displayReservations()
{
    var list = document.getElementById("reservationList");

    if(reservations.length == 0)
    {
        list.innerHTML = "<p>No reservations yet.</p>";
        return;
    }

    var output = "";

    for(var i = 0; i < reservations.length; i++)
    {
        output +=
            "<p>" +
            "<b>Record " + (i + 1) + "</b><br>" +
            "Customer Name: " + reservations[i].name + "<br>" +
            "Room Number: " + reservations[i].room + "<br>" +
            "Number of Days: " + reservations[i].days +
            "</p><hr>";
    }

    list.innerHTML = output;
}