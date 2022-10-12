
function ToggleButton(props) {

    return (
        <div>
            <label className="switch">
                <input id="switchId" type="checkbox" checked={props.theme} onChange={props.onSwitchHandler}></input>
                <span className="slider"></span>
            </label>
        </div> 
    );

}

export default ToggleButton;